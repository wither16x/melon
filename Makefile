# change both macros below if needed
PREFIX := # x86_64-radishos-
INSTALL_DIR := $(HOME)/.local

NASM := nasm
CXX := $(PREFIX)clang++

CFLAGS := -fno-lto \
	-fno-pic \
	-fno-pie \
	-Wall \
	-Wextra \
	-IInclude \
	-std=c++23

SRC := Source
BUILD := Build

ASM_SRCS := $(shell find $(SRC) -type f -name "*.asm")
CXX_SRCS := $(shell find $(SRC) -type f -name "*.cpp")

ASM_OBJS := $(patsubst $(SRC)/%,$(BUILD)/%,$(ASM_SRCS:.asm=.o))
CXX_OBJS := $(patsubst $(SRC)/%,$(BUILD)/%,$(CXX_SRCS:.cpp=.o))

OBJS := $(ASM_OBJS) $(CXX_OBJS)
TARGET := $(BUILD)/melon.a

.PHONY: all clean re install build-install

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	ar rcs $(TARGET) $(OBJS)

$(BUILD)/%.o: $(SRC)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CFLAGS) -c $< -o $@

$(BUILD)/%.o: $(SRC)/%.asm
	@mkdir -p $(dir $@)
	$(NASM) -f elf64 $< -o $@

clean:
	rm -rf $(BUILD)

re: clean all

install:
	./Install.sh $(INSTALL_DIR)

build-install: re install