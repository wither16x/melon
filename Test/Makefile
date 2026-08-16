BUILD := Build

CXX := clang++
CXXFLAGS := -fno-lto -fno-pic -fno-pie -std=c++23 -Wall -Wextra -I../Include -I.

SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,$(BUILD)/%.o,$(SRCS))

TARGET := $(BUILD)/Test

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS) ../Build/libmelon.a
	$(CXX) -fno-pie -no-pie $^ -o $@

$(BUILD)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD)