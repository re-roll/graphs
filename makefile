PROJECT=main
CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -pedantic -lm -fcommon
FUNCTIONS=graph
READ=read
FILES=graphs/hamGraph.txt graphs/hamGraphSimple1.txt graphs/hamGraphSimple2.txt graphs/hamGraphSimple3.txt graphs/nonHamGraph.txt graphs/nonHamGraphSimple1.txt graphs/nonHamGraphSimple2.txt graphs/nonHamGraphSimple3.txt

all: $(PROJECT)

run: $(PROJECT)
	@./$(PROJECT) $(FILES) > current-test.output
	@echo "Test output differences:"
	@diff -w $(PROJECT).output current-test.output

$(PROJECT): $(PROJECT).c $(FUNCTIONS).c $(READ).c 
	$(CC) $(CFLAGS) -o $(PROJECT) $(PROJECT).c $(FUNCTIONS).c $(READ).c

clean:
	@rm -f current-test.output main
