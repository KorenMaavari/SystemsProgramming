CC = gcc
OBJS = tool/AsciiArtTool.o RLEList.o main.o
EXEC = tool/AsciiArtTool
DEBUG_FLAG = # now empty, assign -g for debug
COMP_FLAG = -std=c99 -I/home/mtm/public/2122b/ex1 -I/tool -Wall -pedantic-errors -Werror -DNDEBUG

$(EXEC) : $(OBJS)
	$(CC) $(DEBUG_FLAG) $(OBJS) -o $@
tool/AsciiArtTool.o : tool/AsciiArtTool.c tool/AsciiArtTool.h RLEList.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.c
RLEList.o : RLEList.c RLEList.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.c
tool/main.o : tool/main.c tool/AsciiArtTool.h RLEList.h
	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.c
clean:
	rm -f $(OBJS) $(EXEC)
