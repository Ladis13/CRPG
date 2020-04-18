CC = g++
FLAGS = -g -Wall -Wextra

INC = include
SRC = src
OBJ = obj

vpath %.h $(INC)
vpath %.cpp $(SRC)
vpath %.o $(OBJ)

OBJS = main.o Game.o Character.o Stats.o SStats.o Player.o Item.o Random.o Enemy.o Event.o Weapon.o Inventory.o

VERSION = 0.3.0

main: $(addprefix $(OBJ)/, $(OBJS))
	@mkdir -p data
	$(CC) $(FLAGS) $^ -o $@

obj/main.o: main.cpp Game.h
	@mkdir -p $(OBJ)
	$(CC) $(FLAGS) -c $< -o $@

obj/%.o: %.cpp %.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -r $(OBJ) main
