.SUFFIXES : .c .o
CC = gcc
TARGET = main
DTARGET = main_debug
OBJECTS = main.c manager.o
CFLAGS = -W -Wall
OBJECT = manager.c

$(TARGET) : $(OBJECTS)
	 $(CC) -c $(OBJECT) -o manager.o
	 $(CC) -o $@ $^
$(DTARGET) : $(OBJECTS)
	 $(CC) -DDEBUG -c $(OBJECT) -o manager.o
	 $(CC) -DDEBUG -o $@ $^
clean :	
	 rm *.o main
