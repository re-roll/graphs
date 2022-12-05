PROJECT=main
CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -pedantic -lm -fcommon
FUNCTIONS=graph
READ=read

all: $(PROJECT)

$(PROJECT): $(PROJECT).c $(FUNCTIONS).c $(READ).c 
	$(CC) $(CFLAGS) -o $(PROJECT) $(PROJECT).c $(FUNCTIONS).c $(READ).c

clean:
	rm main