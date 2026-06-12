# !--MakeFile--

CXX=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98 -MMD
SRC=main.cpp Bureaucrat.cpp
OBJS=$(SRC:.cpp=.o)
TARGET=bureaucrat

all: $(TARGET)

-include $(OBJS:.o=.d)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

re: fclean all

run:
	./$(TARGET)

clean:
	rm -f $(OBJS) *.d

fclean: clean
	rm -f $(TARGET)

.PHONY: all re clean fclean