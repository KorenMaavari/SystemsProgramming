#include "AsciiArtTool.h"
#include <stdlib.h>

#define NULL_CHAR '\0'

RLEList asciiArtRead (FILE *in_stream) {
    RLEList res = RLEListCreate();
    if (res == NULL) {
        printf("Malloc Error!\n");
        return 0;
    }
    char symbol;
    while ((symbol = fgetc(in_stream)) != EOF) {
        RLEListAppend(res, symbol);
    }
    return res;
}

RLEListResult asciiArtPrint(RLEList list, FILE *out_stream) {
    if (list == NULL) {
        return RLE_LIST_NULL_ARGUMENT;
    }
    RLEListResult *res = RLE_LIST_SUCCESS;
    int size_of_rlelist = RLEListSize(list);
    char curr_symbol;
    for (int i=0 ; i<size_of_rlelist ; i++) {
        curr_symbol = RLEListGet(list, i, res);
        if (res != RLE_LIST_SUCCESS) {
            return *res;
        }
        fputc(curr_symbol, out_stream);
    }
    return RLE_LIST_SUCCESS;
}

RLEListResult asciiArtPrintEncoded (RLEList list, FILE *out_stream) {
    char *zipped_rlelist = RLEListExportToString(list, 0);
    if (zipped_rlelist == NULL) {
        printf("Malloc Error!\n");
        return RLE_LIST_OUT_OF_MEMORY;
    }
    if (*zipped_rlelist == RLE_LIST_NULL_ARGUMENT) {
        return RLE_LIST_NULL_ARGUMENT;
    }
    fprintf(out_stream, "%s", zipped_rlelist);
    free(zipped_rlelist);
    return RLE_LIST_SUCCESS;
}
/*
char InvertMapAsciiArt(char c){
    if(c == SPACE_CHAR){
        return AT_SIGN;
    }
    else if(c == AT_SIGN){
        return SPACE_CHAR;
    }
    return c;
}
*/
