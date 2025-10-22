SRC_DIR := src
BUILD_DIR := build
TARGET := carbon_copy

SRC := $(wildcard $(SRC_DIR)/*.c)
HEAD := $(wildcard $(SRC_DIR)/*.h)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

CC := gcc 
CFLAGS := -Wall -g 
LDFLAGS := -lm 

.PHONY: all clean 

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
	
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

clean: 
	@rm -rf $(BUILD_DIR)
	@rm -f $(TARGET)



