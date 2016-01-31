# Factor Pro
# By Dan Fiscus

# Macros

# Rules
all::main

main: main.cpp
	$(CXX) -o main $(CXXFLAGS) main.cpp

clean:
	rm -rf *.o main
