CXX = g++
CXXFLAGS = -std=c++14 -I Table-and-Graph-Libs
TARGET = linalg
SOURCES = main_linalg.cpp ClassMethods.cpp LinearRegression.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
