##
## EPITECH PROJECT, 2024
## B-OOP-400-PAR-4-1-raytracer-tom.facon
## File description:
## Makefile
##

SRC = 	data_class/Color.cpp	\
		data_class/Resolution.cpp	\
		data_class/Point3D.cpp	\
		data_class/Vector3D.cpp	\
		data_class/Rectangle3D.cpp	\
		data_class/Ray.cpp	\
		element/Camera.cpp	\
		element/Lights.cpp	\
		element/primitive/APrimitive.cpp	\
		element/primitive/PrimitiveFactory.cpp	\
		element/primitive/Sphere.cpp	\
		element/primitive/Planes.cpp	\
		element/primitive/Cylinder.cpp	\
		element/primitive/Rectangle.cpp	\
		element/primitive/IPrimitive.cpp	\
		element/Element.cpp	\
		display/Display.cpp	\
		parsing/Parser.cpp	\
		src/Error.cpp	\
		src/main.cpp

OBJ = $(SRC:.cpp=.o)

NAME = raytracer

CXX = g++

CXXFLAGS = -std=c++20 -g3

SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

CONFIG_FLAGS = -lconfig++

CXXFLAGS += -I./parsing -I./element -I./data_class -I./element/primitive -I./display

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(SFML_FLAGS) $(CONFIG_FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re