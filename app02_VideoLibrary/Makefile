NAME		=	videoLib
SRCS		=	$(wildcard *.cpp)
OBJS		=	$(SRCS:.c=.o)

all: 
	g++ $(SRCS) --std=c++17 -o $(NAME) 

run: 
	g++ $(SRCS) --std=c++17 -o $(NAME) && ./$(NAME)
