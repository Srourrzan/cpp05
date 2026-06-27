# !--MakeFile--

CXX=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98 -MMD
SRCS= 		main.cpp 					\
			AForm.cpp 					\
			Bureaucrat.cpp				\
			ShrubberyCreationForm.cpp	\
			RobotomyRequestForm.cpp		\
			PresidentialPardonForm.cpp \
			Intern.cpp
OBJS=$(patsubst %.cpp,build/%.o,$(SRCS))
DEPS=$(OBJS:.o=.d)
TARGET=Work

all: $(TARGET)

-include $(DEPS)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

build/%.o: %.cpp
	mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

re: fclean all

run:
	./$(TARGET)

clean:
	rm -f $(OBJS) $(DEPS)
	rm -rf build/
	rm -rf *_shrubbery

fclean: clean
	rm -f $(TARGET)

.PHONY: all re clean fclean
