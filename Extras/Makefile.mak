#========================================================================
CC     = gcc
CFLAGS = -Wall -std=c99 -g -O2 -D_GNU_SOURCE
LFLAGS = `pkg-config --cflags --libs glib-2.0`
#------------------------------------------------------------------------
BIN_DIR = bin
BLD_DIR = obj
INC_DIR = include
SRC_DIR = src
#------------------------------------------------------------------------
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BLD_DIR)/%.o,$(SRC))
#------------------------------------------------------------------------
PROGRAM = guiao-2
#========================================================================

.DEFAULT_GOAL = build

build: setup $(BIN_DIR)/$(PROGRAM)

$(BIN_DIR)/$(PROGRAM): $(OBJS)
	$(CC) -I $(INC_DIR) $(CFLAGS) -o $@ $^ $(LFLAGS)

$(BLD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c -I $(INC_DIR) $(CFLAGS) -o $@ $^ $(LFLAGS)

.PHONY: setup
setup:
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(BLD_DIR)	

.PHONE: clean
clean: 
	@	echo "Cleaning..."
	@-rm -r $(BIN_DIR)
	@-rm -r $(BLD_DIR)
