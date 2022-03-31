OBJS	= main.o TriPath.o TriModel.o PathDependentOptions.o ReadCSVFile.o
SOURCE	= main.cpp TriPath.cpp TriModel.cpp PathDependentOptions.cpp ReadCSVFile.cpp
HEADER	= TriPath.h TriModel.h PathDependentOptions.h ReadCVFile.h
OUT	= main
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

TriPath.o: TriPath.cpp
	$(CC) $(FLAGS) TriPath.cpp 

TriModel.o: TriModel.cpp
	$(CC) $(FLAGS) TriModel.cpp 

PathDependentOptions.o: PathDependentOptions.cpp
	$(CC) $(FLAGS) PathDependentOptions.cpp 

ReadCSVFile.o: ReadCSVFile.cpp
	$(CC) $(FLAGS) ReadCSVFile.cpp 


clean:
	rm -f $(OBJS) $(OUT)