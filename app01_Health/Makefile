NAME		=	healthcare
SRCS		=	$(wildcard *.cpp)
OBJS		=	$(SRCS:.c=.o)

all: 
	g++ $(SRCS) --std=c++17  -lcurl -o $(NAME) 

run: 
	g++ $(SRCS) --std=c++17  -lcurl -o $(NAME) && ./$(NAME)
