#include "RLEList.h"
#include <stdlib.h>
#include <string.h>

#define NULL_CHAR '\0'
#define INVALID -1
#define LINE_BREAK_CHAR '\n'

struct RLEList_t{
    char symbol;
    int repetitions;
    struct RLEList_t* next;
};


RLEList RLEListCreate(){
    RLEList ptr = malloc(sizeof(*ptr));
    if(!ptr){
        return NULL;
    }
    ptr->symbol = NULL_CHAR;// '\0'
    ptr->repetitions = 0;
    ptr->next = NULL;
    return ptr;
}

void RLEListDestroy (RLEList list) {
    while (list != NULL) {
        RLEList to_delete = list;
        list = list->next;
        free(to_delete);
    }
}

RLEListResult RLEListAppend(RLEList list, char value){
    if(value==NULL_CHAR || list==NULL){
        return RLE_LIST_NULL_ARGUMENT;
    }
    while(list->next != NULL){
        list = list->next;
    }
    if(list->symbol==value){
        list->repetitions++;
    }
    else{
        RLEList new_node = RLEListCreate();
        if(new_node==NULL){
            return RLE_LIST_OUT_OF_MEMORY;
        }
        else{
            new_node->symbol = value;
            new_node->repetitions = 1;
            new_node->next = NULL;
        }
        list->next = new_node;
    }
    return RLE_LIST_SUCCESS;
}

int RLEListSize (RLEList list){
    if(list==NULL){
        return INVALID;//-1
    }
    int num_of_characters = 0;
    if(list->next!=NULL){
        list = list->next;
        while (list != NULL) {
            num_of_characters+=list->repetitions;
            list = list->next;
        }
    }
    return num_of_characters;
}

RLEListResult RLEListRemove(RLEList list, int index){
    if(list==NULL){
        return RLE_LIST_NULL_ARGUMENT;
    }
    if(index < 0 || index > RLEListSize(list)-1){
        return RLE_LIST_INDEX_OUT_OF_BOUNDS;
    }
    // valid index and list
    RLEList index_node = list->next;
    while(index!=0){
        if(index >= index_node->repetitions){
            index-=index_node->repetitions;
            index_node = index_node->next;
            list = list->next;
        }
        if(index < index_node->repetitions){
            index = 0 ;
        }
    }
    if(index_node->repetitions == 1){
        list->next = index_node->next;
        free(index_node);
        if(list->next != NULL){
            if(list->symbol == list->next->symbol){
                list->repetitions+=list->next->repetitions;
                RLEList merged_node = list->next;
                list->next = merged_node->next;
                free(merged_node);
            }
        }
    }
    else{//index_node->repetitions > 1
        index_node->repetitions--;
    }
    return RLE_LIST_SUCCESS;
}

char RLEListGet (RLEList list, int index, RLEListResult *result) {
    RLEListResult error_result;
    RLEList head = list;
    if (list == NULL) {
        error_result = RLE_LIST_NULL_ARGUMENT;
    }
    else if (index < 0 || index > (RLEListSize(list) - 1)) {
        error_result = RLE_LIST_INDEX_OUT_OF_BOUNDS;
    }
    else if(list->next==NULL){//empty list
        error_result = RLE_LIST_INDEX_OUT_OF_BOUNDS;
    }
    else{ // valid input
        int next_counter = 0;
        while (next_counter <= index) {
            list = list->next;
            next_counter+=list->repetitions;
        }
        error_result = RLE_LIST_SUCCESS;
    }
    if(result != NULL){
        *result = error_result;
    }
    if(head!=NULL){
        return list->symbol;
    }
    return 0;
}

RLEListResult RLEListMap(RLEList list, MapFunction map_function){
    if(list==NULL || map_function == NULL){
        return RLE_LIST_NULL_ARGUMENT;
    }
    list = list->next;
    while(list!=NULL){
        list->symbol = map_function(list->symbol);
        list = list->next;
    }
    return RLE_LIST_SUCCESS;
}

static int digits (int num) {//return the amount of digits
    int counter =0;
    while(num!=0){
        counter++;
        num=num/10;
    }
    return counter;
}

static char* create_string(char symbol,int repetitions){
    int num_of_digits = digits(repetitions);
    int size_of_string = sizeof(int)*(num_of_digits + sizeof(symbol) + 2);//for /0 and line_break
    char *string = malloc(size_of_string);
    if(string == NULL){
        printf("Memory Error");;
        return NULL;
    }
    for(int k=0;k<size_of_string;k++){
        string[k]=NULL_CHAR;
    }
    string[0]=symbol;
    for(int i=num_of_digits+1;i>1;i--){
        string[i-1] = '0' + repetitions%10;
        repetitions=repetitions/10;
    }
    string[num_of_digits+1] = LINE_BREAK_CHAR;
    return string;
}

char *RLEListExportToString (RLEList list, RLEListResult *result) {
    RLEListResult error_result = RLE_LIST_SUCCESS;
    if (list == NULL) {
        error_result = RLE_LIST_NULL_ARGUMENT;
    }
    else{
        RLEList list_copy = list->next;
        int res_size = 0;
        while (list_copy != NULL) {
            res_size+= sizeof(list_copy->symbol); // for the symbol
            res_size+= digits(list_copy->repetitions);
            res_size+= sizeof(LINE_BREAK_CHAR); // for the \n
            list_copy = list_copy->next;
        }
        char *res = malloc((res_size + 1) * sizeof(*res)); // +1 for the \0
        if (res == NULL) {
            printf("Malloc Error!\n");
            return NULL;
        }
        res[0] = NULL_CHAR;
        list = list->next;
        char *string = NULL;
        while (list != NULL) {
            string = create_string(list->symbol,list->repetitions);
            strcat(res,string);
            list = list->next;
            free(string);
        }
        res[strlen(res)]= NULL_CHAR;
        if (result != NULL) {
            *result = error_result;
        }
        return res;
    }
    if (result != NULL) {
        *result = error_result;
    }
    return NULL;
}
