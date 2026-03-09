CXX = clang++
CXXFLAGS = -std=c++17 -O2
OPENCV = `pkg-config --cflags --libs opencv4`

TARGET = afro_hair
SRC = main.cpp pipeline.cpp utils.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(OPENCV)

clean:
	rm -f $(TARGET)
