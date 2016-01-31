# Factor Pro
# By Dan Fiscus

# Macros
CXXFLAGS = -Os -std=c++14

# Rules
all::main

main: main.cpp
	g++ -o main $(CXXFLAGS) main.cpp

clean:
	rm -rf *.o main
