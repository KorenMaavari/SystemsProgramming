CC = gcc
OBJS = AsciiArtTool.o RLEList.o main.o
EXEC = AsciiArtTool
DEBUG_FLAG = # now empty, assign -g for debug
COMP_FLAG = -std=c99 -I/home/mtm/public/2122b/ex1 -I/tool -Wall -pedantic-errors -Werror -DNDEBUG

$(EXEC) : $(OBJS)
	$(CC) $(DEBUG_FLAG) $(OBJS) -o $@
AsciiArtTool.o : AsciiArtTool.c AsciiArtTool.h RLEList.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.c
RLEList.o : RLEList.c RLEList.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.c
main.o : main.c AsciiArtTool.h RLEList.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.c
clean:
	rm -f $(OBJS) $(EXEC)
