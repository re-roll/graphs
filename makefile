PROJECT=main
CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -pedantic -lm -fcommon
FUNCTIONS=graph
READ=read
FILES=graphs/1.txt graphs/2.txt graphs/3.txt

all: $(PROJECT)

run: $(PROJECT)
	@./$(PROJECT) $(FILES) > current-test.output
	@echo "Test output differences:"
	@diff -w $(PROJECT).output current-test.output

$(PROJECT): $(PROJECT).c $(FUNCTIONS).c $(READ).c 
	$(CC) $(CFLAGS) -o $(PROJECT) $(PROJECT).c $(FUNCTIONS).c $(READ).c

clean:
	@rm -f current-test.output main