CC=gcc
AS=as
CFLAGS=-W -Wall -Wextra -ffreestanding -nostdlib -fno-builtin -fno-stack-protector
BIN_DIR=bin

$(BIN_DIR)/app: $(BIN_DIR)/start.o $(BIN_DIR)/main.o $(BIN_DIR)/io.o
	mkdir -p bin
	$(CC) $(CFLAGS) -g $^ -o $@

$(BIN_DIR)/start.o: start.s
	mkdir -p bin
	$(AS) -g $< -o $@

$(BIN_DIR)/main.o: main.c
	mkdir -p bin
	$(CC) $(CFLAGS) -g -c $< -o $@

$(BIN_DIR)/io.o: io.c
	mkdir -p bin
	$(CC) $(CFLAGS) -g -c $< -o $@

clean:
	rm -r $(BIN_DIR)

.PHONY: clean
