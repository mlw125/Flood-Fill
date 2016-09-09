# Project: ListADT
# Makefile created by Dev-C++ 4.9.9.2
# Modified by Matthew Williams

CPP  = g++
RES  = 
OBJ  = flood_fill2.o $(RES)
LINKOBJ  = flood_fill2.o $(RES)
BIN  = flood_fill2
CXXFLAGS = $(CXXINCS)  
CFLAGS = $(INCS)  
RM = rm -f


all: flood_fill2

clean: 
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o flood_fill2 $(LIBS)

flood_fill.o: flood_fill2.cpp
	$(CPP) -c flood_fill2.cpp -o flood_fill2.o $(CXXFLAGS)
