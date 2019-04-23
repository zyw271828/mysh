TARGET = mysh
LIBS = -lm
CC = gcc
CFLAGS = --std=gnu11 -Wall
RM = rm -f

.PHONY: default all clean

default: $(TARGET)

all: default

$(TARGET): mysh.c cat echo ls mkdir rm wc
	$(CC) mysh.c $(CFLAGS) $(LIBS) -o $@

cat: cat.c
	$(CC) cat.c $(CFLAGS) $(LIBS) -o $@

echo: echo.c
	$(CC) echo.c $(CFLAGS) $(LIBS) -o $@

ls: ls.c
	$(CC) ls.c $(CFLAGS) $(LIBS) -o $@

mkdir: mkdir.c
	$(CC) mkdir.c $(CFLAGS) $(LIBS) -o $@

rm: rm.c
	$(CC) rm.c $(CFLAGS) $(LIBS) -o $@

wc: wc.c
	$(CC) wc.c $(CFLAGS) $(LIBS) -o $@

clean:
	$(RM) $(TARGET)
	$(RM) cat
	$(RM) echo
	$(RM) ls
	$(RM) mkdir
	$(RM) rm
	$(RM) wc