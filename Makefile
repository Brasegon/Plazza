NAME	= plazza

CC	= g++

RM	= rm -f

SRCS	= ./src/kitchen/Kitchen.cpp \
	  ./src/main.cpp \
	  ./src/order/Order.cpp \
	  ./src/reception/Reception.cpp 

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./src/kitchen/pp
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
