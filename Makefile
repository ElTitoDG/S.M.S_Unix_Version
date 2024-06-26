# Modified Makefile template for C code
#
# Author: Julián Hinojosa Gil
# Original Author: Gustavo Pantuza Coelho Pinto
# Since: 24.03.2016

# Includes the project configurations
include project.conf

# Validating project variables defined in project.conf
ifndef PROJECT_NAME
	$(error Missing PROJECT_NAME. Put variables at project.conf file)
endif
ifndef BINARY
	$(error Missing BINARY. Put variables at project.conf file)
endif
ifndef PROJECT_PATH
	$(error Missing PROJECT_PATH. Put variables at project.conf file)
endif

# Gets the Operating system name
OS := $(shell uname -s)

# Default shell and compiler based on the operating system
ifeq ($(OS),Darwin)
    SHELL := zsh
    CC := clang
    COLOR_PREFIX := 033
else
    SHELL := bash
    CC := gcc
    COLOR_PREFIX := e
endif

# Color definition for print purpose
BROWN=\$(COLOR_PREFIX)[0;33m
BLUE=\$(COLOR_PREFIX)[1;34m
END_COLOR=\$(COLOR_PREFIX)[0m

# Source code directory structure
BINDIR := bin
SRCDIR := src
LIBDIR := lib

# Source code file extension
SRCEXT := c

# Defines the language standards for GCC
STD := -std=c17 #See man gcc for more options

# Protection for stack-smashing attack
STACK := -fstack-protector-all -Wstack-protector

# Specifies to GCC the required warnings
WARNS := -Wall -Wextra # -pedantic warns on language standards

# Flags for compiling
CFLAGS := -O3 $(STD) $(STACK) $(WARNS)

# Debug options
DEBUG := -g3 -DDEBUG=1

# Dependency libraries
#LIBS :=  -lm  -I some/path/to/library

# %.o file names
NAMES := $(notdir $(basename $(wildcard $(SRCDIR)/*.$(SRCEXT))))
OBJECTS := $(patsubst %,$(LIBDIR)/%.o,$(NAMES))

# COMPILATION RULES

default: help

# Help message
help:
	@echo "$(BLUE)S.M.S Unix Version$(END_COLOR)"
	@echo
	@echo "Target rules:"
	@echo "    all      - Compiles and generates binary file"
	@echo "    run      - Run the current binary file"
	@echo "    clean    - Clean the project by removing binaries"
	@echo "    help     - Prints a help message with target rules"
	@echo

# Rule for link and generate the binary file
all: $(BINDIR)/$(BINARY)

# Link and generate the binary file
$(BINDIR)/$(BINARY): $(OBJECTS)
	@echo -en "$(BROWN)LD $(END_COLOR)"
	@mkdir -p $(BINDIR)
	$(CC) -o $@ $^ $(DEBUG) $(CFLAGS) $(LIBS)
	@echo -en "--\nBinary file placed at $(BROWN)$@$(END_COLOR)\n"

# Run command
run:
	./$(BINDIR)/$(BINARY)

# Rule for object binaries compilation
$(LIBDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo -en "$(BROWN)$(CC) $(END_COLOR)"
	@mkdir -p $(LIBDIR)
	$(CC) -c $^ -o $@ $(DEBUG) $(CFLAGS) $(LIBS)

# Rule for cleaning the project
clean:
	@rm -rvf $(BINDIR)/* $(LIBDIR)/*