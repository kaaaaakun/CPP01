# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 16:08:51 by tokazaki          #+#    #+#              #
#    Updated: 2023/12/07 00:08:40 by tokazaki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = file_replace

# Files & Command +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
SRCS	= \
	main.cpp \
	FileReplace.cpp

OBJDIR	= obj
OBJS    = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
DEPENDS	= $(OBJS:.o=.d)

# -- flags --
CXX 		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -g
CXXFLAGS	+= -MMD -MP

# -- command --
RM		= rm -rf

# Mandatory target ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# Other targets +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
.PHONY: all clean fclean re

cfile:
	find . -name "*.cpp" | sed 's/\.\///g' \
		| awk '{print "\t"$$0" \\"}' | sed '$$s/ \\//' | pbcopy

run: all
	./file_replace Makefile " " "+" ; cat Makefile.replace

del: fclean
	$(RM) *.replace

-include $(DEPENDS)
#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#

