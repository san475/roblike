# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# the build target executable:
TARGET = roblike
MAIN = main
PLAYER = player
MAP = map
OBJECTS = $(MAIN).o $(PLAYER).o $(MAP).o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) -lncurses

$(MAIN).o : $(MAIN).c $(MAIN).h
	$(CC) $(CFLAGS) -c $(MAIN).c -lncurses

$(PLAYER).o : $(PLAYER).c $(PLAYER).h
	$(CC) $(CFLAGS) -c $(PLAYER).c -lncurses

$(MAP).o : $(MAP).c $(MAP).h
	$(CC) $(CFLAGS) -c $(MAP).c -lncurses

clean:
	$(RM) $(TARGET) *.o
