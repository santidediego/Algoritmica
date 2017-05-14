INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = #-Wall -g


all: $(BIN)/prueba

# ************ Compilación de módulos ************

$(BIN)/prueba : $(OBJ)/main.o $(OBJ)/greedy.o 
	$(CXX) -o $(BIN)/prueba $(OBJ)/main.o $(OBJ)/greedy.o

$(OBJ)/main.o : $(INC)/greedy.h $(SRC)/main.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/greedy.o : $(INC)/greedy.h $(SRC)/greedy.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/greedy.o $(SRC)/greedy.cpp

# ************ Limpieza ************
clean :
	echo "Limpiando..."
	rm -f $(OBJ)/*.o

mrproper : clean
	rm -f $(BIN)/*
