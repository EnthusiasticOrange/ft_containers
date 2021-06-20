CC = clang++
NAME = ft_containers
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = \
	containers/list/detail/list_node.cpp \
	other/red_black_tree/rb_node.cpp \
	tests/list/list_tests.cpp \
	tests/map/map_tests.cpp \
	tests/queue/queue_tests.cpp \
	tests/stack/stack_tests.cpp \
	tests/vector/vector_tests.cpp \
	tests/tests.cpp \
	tests/util/Dummy.cpp \
	main.cpp

OBJ = $(patsubst %.cpp, %.o, $(SRC))

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c -o $@ $< -I.

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

