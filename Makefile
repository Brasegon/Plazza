NAME	= plazza

CC	= g++

RM	= rm -f

SRCS	= ./src/encapsulation/Encapsulation.cpp \
	  ./src/kitchen/Kitchen.cpp \
	  ./src/main.cpp \
	  ./src/order/Order.cpp \
	  ./src/order/pizzaOrder/pizzaType.cpp \
	  ./src/pizza/Pizza.cpp \
	  ./src/pizza/pizzaType/MargaritaPizza.cpp \
	  ./src/pizza/pizzaType/ReginaPizza.cpp \
	  ./src/reception/Reception.cpp 

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./src/encapsulation/pp
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
