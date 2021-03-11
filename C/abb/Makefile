CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g
CC = gcc
TARGET = dict

all: $(TARGET)

$(TARGET) : main.c dict.o string.o helpers.o dict_helpers.o

	$(CC) $(CFLAGS) -o $(TARGET) $^

run_main: $(TARGET)
	valgrind --show-reachable=yes --leak-check=full ./$(TARGET)

.PHONY : clean

clean:
	rm -f *.o $(TARGET) $(TEST)