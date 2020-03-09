#Code for this make file adapted from:
#https://stackoverflow.com/a/14589770
#and
#https://stackoverflow.com/a/14590222

CXX=g++
CPPFLAGS= -g -std=c++11 -I.
LD=$(CC)
#LDFLAGS = -lfoo

SOURCES=$(shell find . -type f -iname '*.cpp')

OBJECTS=$(foreach x, $(basename $(SOURCES)), $(x).o)

TARGET=ChocAn

$(TARGET): $(OBJECTS)
	$(CXX) $^ -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)
