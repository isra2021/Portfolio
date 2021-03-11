CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g
CC = gcc
TARGET = queue

all: $(TARGET)

$(TARGET) : main.c queue.o

	$(CC) $(CFLAGS) -o $(TARGET) $^

run_main: $(TARGET)
	valgrind --show-reachable=yes --leak-check=full ./$(TARGET)

.PHONY : clean

clean:
	rm -f *.o $(TARGET) $(TEST)