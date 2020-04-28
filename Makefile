NAME	= plazza

CC	= g++

RM	= rm -f

SRCS	= ./src/main.cpp \
	  ./src/reception/Reception.cpp 

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./src/pp
CPPFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
