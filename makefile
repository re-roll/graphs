PROJECT=main
CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -pedantic -lm -fcommon
FUNCTIONS=graph

all: $(PROJECT)

$(PROJECT): $(PROJECT).c $(FUNCTIONS).c 
	$(CC) $(CFLAGS) -o $(PROJECT) $(PROJECT).c $(FUNCTIONS).c 