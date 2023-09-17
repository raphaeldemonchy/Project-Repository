CC=g++
CFLAGS=-c -std=c++20
SOURCES=$(wildcard *.cpp\
					KITCHEN/*.cpp\
					RECEPTION/*.cpp\
					KITCHEN/THREADS/*.cpp\
					KITCHEN/FRIDGE/*.cpp -g3)


OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=plazza

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -luuid -lzmq -o $@
%.o: %.cpp
	$(CC) $(CFLAGS) $< -luuid -o $@

clean:
	rm -rf $(OBJECTS)

fclean:
	rm -rf $(EXECUTABLE)

re: fclean all clean