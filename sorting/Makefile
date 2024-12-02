NAME		=	test
CXX			=	c++
CXXFLAGS	=	-std=c++17
RM			=	rm -rf
SRCS		=	test.cpp
OBJS		=	$(SRCS:%.cpp=%.o)
all		: $(NAME)
%.o		: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<
$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
clean	:
	$(RM) $(OBJS)
fclean	:	clean
	$(RM) $(NAME)
re		:	fclean all
.PHONY	:	all clean fclean re