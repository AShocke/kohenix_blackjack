CC = g++
tests =  database_test

all: main $(tests)

main:  logic.o training.o
	$(CC) main.cpp database.cpp blackjack.cpp logic.cpp training.cpp -o $@	

tests: $(tests)

database_test: logic.o
	$(CC) tests/database_test.cpp logic.cpp	database.cpp -o $@ 

.PHONY: clean
clean:
	-rm *.o 
	-rm $(tests) main 
	$(MAKE) clean -C database
DDA456: 
	$(MAKE) DDA456 -C database



