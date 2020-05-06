NAME	= plazza

CC	= g++

RM	= rm -f

SRCS	= ./src/cooker/cooker.cpp \
	  ./src/encapsulation/Encapsulation.cpp \
	  ./src/kitchen/Kitchen.cpp \
	  ./src/main.cpp \
	  ./src/order/Order.cpp \
	  ./src/order/pizzaOrder/pizzaType.cpp \
	  ./src/pizza/Pizza.cpp \
	  ./src/pizza/pizzaType/MargaritaPizza.cpp \
	  ./src/pizza/pizzaType/ReginaPizza.cpp \
	  ./src/reception/Reception.cpp \
	  ./src/kitchen/pizzaCooking/pizzaCooking.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./src/cooker/pp
CPPFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -lpthread

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
