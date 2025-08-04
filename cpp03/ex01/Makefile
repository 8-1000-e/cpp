# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 11:09:48 by edubois-          #+#    #+#              #
#    Updated: 2025/05/05 15:55:40 by edubois-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ScavTrap

SRCS =  main.cpp\
		ClapTrap.cpp\
		ScavTrap.cpp\
				
OBJS = $(SRCS:.cpp=.o)

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

all: $(NAME)
	@echo "Compilation terminée : $(NAME) est prêt !"

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(CXXFLAGS) $(OBJS)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@echo "Les fichiers objets ont été supprimés."

fclean: clean
	$(RM) $(NAME)
	@echo "L'exécutable $(NAME) a été supprimé."

re: fclean all

.PHONY: all clean fclean re