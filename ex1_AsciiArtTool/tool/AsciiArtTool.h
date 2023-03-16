#ifndef ASCIIARTTOOL_H_INCLUDED
#define ASCIIARTTOOL_H_INCLUDED

#include "RLEList.h"

RLEList asciiArtRead(FILE* in_stream);
RLEListResult asciiArtPrint(RLEList list, FILE *out_stream);
RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream);


#endif // ASCIIARTTOOL_H_INCLUDED
