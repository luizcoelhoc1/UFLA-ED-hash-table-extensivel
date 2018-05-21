CXX = g++
CXXFLAGS = -Wall
OBJ = main.o bloco.o hash.o musical.o


main: $(OBJ)
	$(CXX) $(OBJ) $(CXXFLAGS) -o $@
main.o: main.cpp
	$(CXX) -c $< $(CXXFLAGS)
bloco.o: bloco.cpp
	$(CXX) -c $< $(CXXFLAGS)
hash.o: hash.cpp
	$(CXX) -c $< $(CXXFLAGS)
musical.o: musical.cpp
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -rf *.o main
