MAIN = matrix
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

outboot: $(OBJ)
	g++ -o $(MAIN) $(OBJ)

%.o: %.cpp
	g++ -c $< -o $@

clean:
	rm $(OBJ) outboot

run: $(OBJ)
	g++ -o $(MAIN) $(OBJ)
	./$(MAIN)
