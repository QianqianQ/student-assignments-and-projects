CC=g++
CPPFLAGS=-c -g -std=c++0x -Wall -Wextra -pedantic -I ../test
SOURCES=main.cpp ../test/book.cpp ../test/book.hpp \
	../test/customer.cpp ../test/customer.hpp library.cpp library.hpp
OBJECTS=main.o ../test/book.o ../test/customer.o library.o
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)
  
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@ 

.cc.o:
	$(CC) $(CPPFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

run: main
	./main
