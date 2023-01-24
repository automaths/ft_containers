

NAME	=	containers

CC		=	c++

FLAGS	=	-Wall -Wextra -Werror -g -MMD -MP -std=c++98

SRC		=	main.cpp \
			error_check_map.cpp \
			error_check_vector.cpp \

OBJ		:=	$(addprefix ./obj/,$(SRC:%.cpp=%.o))

DEP		=	$(addprefix ./obj/,$(OBJ:%.o=%.d))

RM		=	rm -rf

all: $(NAME)

-include $(DEP)

./obj/%.o: ./%.cpp
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) obj/

fclean:
	$(RM) obj/
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re