CC=g++
CFLAGS=-c -std=c++20
SOURCES=$(wildcard main.cpp\
				   GUI/*.cpp\
				   PARSER/*.cpp\
				   GRAPHICAL/*.cpp\
				   GRAPHICAL/CAMERA/*.cpp\
				   GRAPHICAL/ATH/*.cpp\
				   ANIMATION/*.cpp\
				   CLIENT/*.cpp -g3)


OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=zappy_gui

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -luuid -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -o $@
%.o: %.cpp
	$(CC) $(CFLAGS) $< -luuid -o $@

clean:
	rm -rf $(OBJECTS)

fclean:
	rm -rf $(EXECUTABLE)

re: fclean all clean