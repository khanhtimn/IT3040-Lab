CC = g++
CFLAGS = -std=c++11 -Wall -Wextra

TARGET_DIR = target

# Week directories
WEEKS = $(wildcard week*)

# Targets
all: $(WEEKS)

$(WEEKS):
	@echo "Building targets for $@..."
	$(MAKE) -C $@ TARGET_DIR=../$(TARGET_DIR)/week$(@:week%=%)

.PHONY: all $(WEEKS) clean

clean:
	rm -rf $(TARGET_DIR)
