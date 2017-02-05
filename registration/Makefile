TARGET += main

all: $(TARGET)

CXX = g++
INCPATH = -I./
CFLAGS = -std=c++11 -msse2 -fPIC -O3 -Wall $(INCPATH)
SRC = $(wildcard *.cc)
OBJ = $(SRC:.cc=.o)
LDFLAGS = 

deps: $(SRC)
	$(CXX) $(CFLAGS) -MM -c $^ > $@

%.o: %.cc
	$(CXX) $(CFLAGS) -o $@ -c $(filter %.cc, $^)

sinclude deps

main: $(OBJ)
	$(CXX) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGET)
	rm -f *.o
	rm -f deps
