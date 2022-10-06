SOURCES=main.cxx qvalue.cxx
OBJECTS=main.o qvalue.o

main.h:

%.o: %.cxx %.h
	$(CXX) -g -std=c++11 -c $< -o $@

sim: $(OBJECTS)
	$(CXX) -g $(OBJECTS) -o sim
