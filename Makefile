CC = g++
TARGET = main
OBJS = Disk.o Movie.o Game.o Customer.o Register.o Shelf.o TransactionInfo.o

all: $(TARGET)

$(TARGET): $(OBJS) main.cpp Disk.h Disk.cpp Movie.h Movie.cpp Game.h Game.cpp Customer.h Customer.cpp Register.h Register.cpp Shelf.h Shelf.cpp TransactionInfo.h TransactionInfo.cpp
	$(CC) main.cpp -o $(TARGET) $(OBJS)

$(OBJS): %.o: %.cpp %.h
	$(CC) -c $< -o $@

clean:
	rm -f $(TARGET) *.o 


# all of the files are as follows:
# Disk.h Disk.cpp Movie.h Movie.cpp Game.h Game.cpp Customer.h Customer.cpp Register.h Register.cpp Shelf.h Shelf.cpp TransactionInfo.h TransactionInfo.cpp main.cpp
# Disk.o Movie.o Game.o Customer.o Register.o Shelf.o 