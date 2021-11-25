CXX := g++
CXXFLAGS := -Wall -g -O2 -march=ivybridge -pipe -std=c++20
MAKE_OPTS="-j4"

SRC_PATH := LongN
OBJ_MODULES := BigNum.o
BUILD_PATH := build
BIN_PATH := bin

all: makedirs build

makedirs:
	@mkdir -p $(BUILD_PATH) $(BIN_PATH)

%.o: $(SRC_PATH)/%.cpp $(SRC_PATH)/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $(BUILD_PATH)/$@

build: $(OBJ_MODULES)
	$(CXX) $(CXXFLAGS) $(SRC_PATH)/main.cpp $(addprefix $(BUILD_PATH)/, $^) -o $(BIN_PATH)/lab2

run:
	./$(BIN_PATH)/lab2