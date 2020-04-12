CC = g++
FLAGS = -g -Wall -Wextra

INC = include
SRC = src
OBJ = obj

vpath %.h $(INC)
vpath %.cpp $(SRC)
vpath %.o $(OBJ)

VERSION = 0.1.0

main: $(addprefix $(OBJ)/, main.o Game.o Character.o Stats.o SStats.o Player.o Item.o)
	$(CC) $(FLAGS) $^ -o $@

obj/main.o: main.cpp
	@mkdir -p $(OBJ)
	$(CC) $(FLAGS) -c $< -o $@

obj/%.o: %.cpp %.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -r $(OBJ)
