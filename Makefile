# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 17:50:59 by fmonbeig          #+#    #+#              #
#    Updated: 2021/09/27 15:09:02 by fmonbeig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				pipex
NAME_BONUS =		pipex_b

CC =		clang
CFLAG =		-Wall -Wextra -Werror

LIBFT_PATH=	libft/
LIBFT_LIB=	libft.a

SRC =		pipex_normal/pipex.c\
			pipex_normal/init.c\
			pipex_normal/process.c\
			pipex_normal/utils.c\
			pipex_normal/free.c\
			pipex_normal/error.c\

SRC_BONUS =	pipex_bonus/pipex_bonus.c\
			pipex_bonus/init_bonus.c\
			pipex_bonus/process_bonus.c\
			pipex_bonus/utils_bonus.c\
			pipex_bonus/free_bonus.c\
			pipex_bonus/error_bonus.c\
			pipex_bonus/get_next_line/get_next_line.c\
			pipex_bonus/get_next_line/get_next_line_utils.c\
			pipex_bonus/here_doc.c\
			pipex_bonus/close_fd.c\
			

SRC_OBJ =			$(SRC:.c=.o)	
SRC_OBJ_BONUS =		$(SRC_BONUS:.c=.o)
LIBFT_OBJ=			${LIBFT_PATH}*.o

LIBFT =				$(addprefix $(LIBFT_PATH),libft.a)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(SRC_OBJ)
		@echo "\\n\033[32;1m ***     MAKE_LIB     ***\033[0m \\n"
		$(MAKE) -C ${LIBFT_PATH}
		@echo "\\n\033[34;1m ***PIPEX COMPILATION*** \033[0m \\n"
		$(CC)  $(CFLAG) -o $(NAME) $(SRC_OBJ) ${LIBFT_OBJ}
		@echo "\\n\033[31;1m --- COMPILATION FINISH --- \033[0m \\n"

$(NAME_BONUS): $(SRC_OBJ_BONUS)
		@echo "\\n\033[32;1m ***     MAKE_LIB     ***\033[0m \\n"
		$(MAKE) -C ${LIBFT_PATH}
		@echo "\\n\033[36;1m ***BONUS*** PIPEX_BONUS COMPILATION ***BONUS*** \033[0m \\n"
		$(CC) $(CFLAG) -o $(NAME_BONUS) $(SRC_OBJ_BONUS) ${LIBFT_OBJ}
		@echo "\\n\033[31;1m --- COMPILATION FINISH --- \033[0m \\n"

clean:
				make -C ${LIBFT_PATH} clean
				rm -f ${SRC_OBJ} $(SRC_OBJ_BONUS)

fclean: 		clean
				rm -f ${NAME} $(NAME_BONUS) ${LIBFT_PATH}${LIBFT_LIB}

re:         	fclean all

.PHONY:        all clean fclean re