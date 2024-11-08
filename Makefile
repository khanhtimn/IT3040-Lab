ifeq ($(OS),Windows_NT)
	COMPILER = zig c++
    RM = del /q
    MKDIR = mkdir
    TARGET_PATH = ..\$(TARGET_DIR)\week
else
	COMPILER = g++
    RM = rm -rf
    MKDIR = mkdir -p
    TARGET_PATH = ../$(TARGET_DIR)/week
endif

CC = $(COMPILER)
CFLAGS = -std=c++17 -Wall -Wextra
TARGET_DIR = target

# Week directories
WEEKS = $(wildcard week*)

# Targets
all: $(WEEKS)

$(WEEKS):
	@echo "Building targets for $@..."
	$(MAKE) -C $@ TARGET_DIR="$(TARGET_PATH)$(@:week%=%)"

.PHONY: all $(WEEKS) clean

clean:
	$(RM) $(TARGET_DIR)
