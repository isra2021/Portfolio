CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g 
CC = gcc
TARGET = knapsack

all: $(TARGET)

$(TARGET) : main.c item.o knapsack.o string.o helpers.o -lm

	$(CC) $(CFLAGS) -o $(TARGET) $^

run_main: $(TARGET)
	valgrind --show-reachable=yes --leak-check=full ./$(TARGET)

.PHONY : clean

clean:
	rm -f *.o $(TARGET) $(TEST)