TARGET = test_binary_search_tree
CC = g++
CC_FLAGS = -Wall


all: clean $(TARGET) test

%: %.cpp
	$(CC) $(CC_FLAGS) $*.cpp -o $*

clean:
	rm -f $(TARGET)

test:
	./$(TARGET)
