CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g 
CC = gcc
TARGET = dijkstra

all: $(TARGET)

$(TARGET) : main.c graph.o set.o cost.o dijkstra.o -lm

	$(CC) $(CFLAGS) -o $(TARGET) $^

run_main: $(TARGET)
	valgrind --show-reachable=yes --leak-check=full ./$(TARGET)

.PHONY : clean

clean:
	rm -f graph.o cost.o dijkstra.o $(TARGET) $(TEST)