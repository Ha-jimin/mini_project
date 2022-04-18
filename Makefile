.SUFFIXES : .c .o
CC = gcc
TARGET = main
DTARGET = main_debug
OBJECTS = main.c manager.o
OBJECT = manager.c
CFLAGS = -W -Wall

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -c $(OBJECT) -o $@
	$(CC) $(CFLAGS) -o $@ $^

$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -c $(OBJECT) -o $@
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^

clean : 
	rm *.o main
