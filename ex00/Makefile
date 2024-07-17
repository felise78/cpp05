NAME 		= 	bureaucrat
CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

SRC_FILES	=	main.cpp \
				Bureaucrat.cpp 

OBJ_FILES 	=	$(SRC_FILES:.cpp=.o)
OBJ			=	$(addprefix obj/, $(OBJ_FILES))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

obj/%.o : %.cpp
	@mkdir -p obj/
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf obj/

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re