CC = g++
CFLAGS = -std=c++11 -Wall -Wextra

SOURCES = $(wildcard [1]-*.cpp)

EXECS = $(addprefix $(TARGET_DIR)/, $(notdir $(SOURCES:.cpp=)))

all: $(EXECS)

$(TARGET_DIR)/%: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: all clean

clean:
	rm -f $(EXECS)
