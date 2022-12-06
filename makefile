PROJECT=main
CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -pedantic -lm -fcommon
FUNCTIONS=graph
READ=read
FILES=graphs/graph.txt graphs/graph_new.txt

all: $(PROJECT)

run: $(PROJECT)
	@./$(PROJECT) $(FILES) > current-test.output
	@echo "\nTest output differences:"
	@diff -c $(PROJECT).output current-test.output

$(PROJECT): $(PROJECT).c $(FUNCTIONS).c $(READ).c 
	$(CC) $(CFLAGS) -o $(PROJECT) $(PROJECT).c $(FUNCTIONS).c $(READ).c

clean:
	rm -f current-test.output main