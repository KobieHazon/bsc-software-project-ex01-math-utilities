CC ?= cc
CFLAGS ?= -std=c99 -Wall -Wextra -Werror -pedantic-errors
CPPFLAGS ?= -Iinclude

BUILD_DIR := build
EXEC := $(BUILD_DIR)/ex1
UNIT_EXEC := $(BUILD_DIR)/test_mathisfun

.PHONY: all test unit-test sample-test clean

all: $(EXEC)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/MathIsFun.o: src/MathIsFun.c include/MathIsFun.h | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/main.o: src/main.c include/MathIsFun.h | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/test_mathisfun.o: tests/test_mathisfun.c include/MathIsFun.h | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(EXEC): $(BUILD_DIR)/main.o $(BUILD_DIR)/MathIsFun.o
	$(CC) $^ -o $@

$(UNIT_EXEC): $(BUILD_DIR)/test_mathisfun.o $(BUILD_DIR)/MathIsFun.o
	$(CC) $^ -o $@

test: unit-test sample-test

unit-test: $(UNIT_EXEC)
	$(UNIT_EXEC)

sample-test: $(EXEC)
	python3 tests/run_samples.py $(EXEC)

clean:
	rm -rf $(BUILD_DIR)
