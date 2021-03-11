CFLAGS = -Wall -Werror -Wextra -pedantic -no-pie -std=c99 -g
CC = gcc
TARGET = set

all: $(TARGET)

$(TARGET) : test_set.c set.o list-x86_64.o 

	$(CC) $(CFLAGS) -o $(TARGET) $^

run_main: $(TARGET)
	valgrind --show-reachable=yes --leak-check=full ./$(TARGET)

.PHONY : clean

clean:
	rm -f set.o $(TARGET) $(TEST)