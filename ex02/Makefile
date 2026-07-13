NAME	:=	PmergeMe

SRC_DIR := src
BUILD_DIR	:=	.build
INC_DIR := includes

SRC_FILES		:=	\
main.cpp \
CompareSecond.cpp \
CompareFirst.cpp

SRC		:=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ			:=	$(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEP			:=	$(OBJ:.o=.d)

CXX			:=	c++
CXXFLAGS	:=  -Wall -Wextra -Werror -g3 -std=c++98
INCLUDE		:=	-I$(INC_DIR) -MMD -MP

MAKEFLAGS	+=	--no-print-directory

RM			:=	rm -f
RMF			:=	rm -rf

all	:	$(NAME)

$(NAME)	:	$(OBJ)
			$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(BUILD_DIR):
			@mkdir -p $@

$(BUILD_DIR)/%.o:	$(SRC_DIR)/%.cpp | $(BUILD_DIR)
			@echo "Compilation de $@"
			$(CXX) $(CXXFLAGS) $(INCLUDE) -c -o $@ $<

-include $(DEP)

clean:
			$(RM) $(OBJ) $(DEP)
			$(RMF) $(BUILD_DIR)

fclean:	clean
			$(RM) $(NAME)

re:
			$(MAKE) fclean
			$(MAKE) all

.PHONY:	all clean fclean re
