CXXFLAGS += -MMD  # Generate .d files (contain header dependencies)
-include $(SRC:.cpp=.d)  # Include generated .d files

CXX = g++
CXXFLAGS = -std=c++11 -Wall -MMD
LDFLAGS = 

# Replace utils.cpp with all .cpp files created
SRC = main.cpp player.cpp wheel.cpp

OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d) 
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Run "make" to compile and generate necessary files
# Run "./main" to run generated executable
# Run "make run" to do all of the above in one command
run: $(EXEC)
	./$(EXEC)

# Run "make clean" to clear all generated files
clean:
	rm -f $(OBJ) $(EXEC) $(DEP)
