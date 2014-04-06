TARGET := test

CXXFLAGS := -g -Wall -Werror
LIBS :=

all: $(TARGET)

$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)

clean:
	$(RM) *.o *.d $(TARGET)

.PHONY: all clean
