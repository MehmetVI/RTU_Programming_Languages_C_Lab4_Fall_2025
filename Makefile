CC      := gcc
CFLAGS  := -std=c11 -Wall -Wextra -Wpedantic -O2
LDFLAGS := 
BIN_DIR := bin
SRC_DIR := src

TASK1 := $(BIN_DIR)/task1_dynamic_array
TASK2 := $(BIN_DIR)/task2_student_record
TASK3 := $(BIN_DIR)/task3_student_db

.PHONY: all run clean

all: $(TASK1) $(TASK2) $(TASK3)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(TASK1): $(BIN_DIR) $(SRC_DIR)/task1_dynamic_array.c
	$(CC) $(CFLAGS) $(SRC_DIR)/task1_dynamic_array.c -o $@ $(LDFLAGS)

$(TASK2): $(BIN_DIR) $(SRC_DIR)/task2_student_record.c
	$(CC) $(CFLAGS) $(SRC_DIR)/task2_student_record.c -o $@ $(LDFLAGS)

$(TASK3): $(BIN_DIR) $(SRC_DIR)/task3_student_db.c
	$(CC) $(CFLAGS) $(SRC_DIR)/task3_student_db.c -o $@ $(LDFLAGS)

run: all
	@echo "---- Task1 ----"; echo "5\n34 39 38 49 55" | $(TASK1); \
	 echo "---- Task2 ----"; printf "Alice Johnson\n20\n9.1\n" | $(TASK2); \
	 echo "---- Task3 ----"; printf "3\nAlice Johnson\n20\n9.1\nBob Stone\n19\n7.5\nCarol Lee\n21\n8.3\n" | $(TASK3)

clean:
	rm -rf $(BIN_DIR)
