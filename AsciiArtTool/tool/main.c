char InvertMapAsciiArt(char c);

#include "AsciiArtTool.h"
#define FLAG 1
#define SOURCE_FILE_ARGV 2
#define TARGET_FILE 3
#define ENCODED_CHAR 'e'
#define INVERTED_CHAR 'i'
#define SPACE_CHAR ' '
#define AT_SIGN '@'

int main(int argc,char** argv){
    FILE *source_file = fopen(argv[SOURCE_FILE_ARGV],"r");
    FILE *target_file = fopen(argv[TARGET_FILE],"w");
    if(source_file == NULL){
        printf("Source file open failed \n");
        return 0;
    }
    RLEList ascii_art_list = asciiArtRead(source_file);
    if(ascii_art_list==NULL){
        printf("Memory Error");
        return 0;
    }
    if(argv[FLAG][1] == ENCODED_CHAR){
        asciiArtPrintEncoded(ascii_art_list,target_file);
    }
    else if(argv[FLAG][1] == INVERTED_CHAR){
        RLEListMap(ascii_art_list,InvertMapAsciiArt);
        asciiArtPrint(ascii_art_list,target_file);
    }
    RLEListDestroy(ascii_art_list);
    fclose(source_file);
    fclose(target_file);
    return 0;
}

char InvertMapAsciiArt(char c){
    if(c == SPACE_CHAR){
        return AT_SIGN;
    }
    else if(c == AT_SIGN){
        return SPACE_CHAR;
    }
    return c;
}
