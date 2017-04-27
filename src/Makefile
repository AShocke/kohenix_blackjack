CC := g++
tests :=  database_test
TARGET := main
INC := 
SRCDIR := 
SRCEXT := cc 
SOURCES := main.cc database.cc logic.cc game.cc
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

all: $(TARGET) $(tests)

$(TARGET): $(OBJECTS)
	$(CC) $(SOURCES) -o $(TARGET)

%.o: $(SRCDIR)/%.$(SRCEXT)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

tests: $(tests)

database_test: 
	$(CC) test/database_test.cc logic.cc database.cc -o $@ 

.PHONY: clean
clean:
	-rm -r  $(TARGET)
	-rm $(tests) main 
	$(MAKE) clean -C database
DDA456: 
	$(MAKE) DDA456 -C database



