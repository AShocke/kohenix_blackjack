CC := g++
tests :=  database_test
SRCDIR := src
BUILDIR := build
BINDIRi := bin/
TARGET := bin/main
SRCEXT := cpp
INC := -I include
SOURCES := src/main.cpp src/database.cpp src/blackjack.cpp src/logic.cpp src/training.cpp
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

all: $(TARGET) $(tests)

$(TARGET): $(OBJECTS)
	$(CC) $(SOURCES) -o $(TARGET)

$(BUILDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDIR)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

#training:
#	$(CC) -c logic.cpp database.cpp blackjack.cpp 

#logic:p
#	$(CC) -c logic.cpp database.cpp

tests: $(tests)

database_test: 
	$(CC) test/database_test.cpp src/logic.cpp src/database.cpp -o bin/$@ 

.PHONY: clean
clean:
	-rm -r $(BUILDIR) $(TARGET)
	-rm $(tests) main 
	$(MAKE) clean -C database
DDA456: 
	$(MAKE) DDA456 -C database



