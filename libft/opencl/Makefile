# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchaumar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/23 12:31:27 by cchaumar          #+#    #+#              #
#    Updated: 2017/07/13 07:22:47 by cchaumar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLG   = -Wextra -Wall -Werror -g

ifeq ($(ASAN),1)
	CFLG += -fsanitize=address
endif

ifeq ($(FAST),1)
	CFLG += -Ofast
endif

FILES  = ft_opencl.c kernel.c devices.c run.c
SRCD   = srcs/
OBJD   = objs/
SRCS   = $(addprefix $(SRCD),$(FILES))
OBJS   = $(addprefix $(OBJD),$(FILES:.c=.o))
INCD   = includes/
LIBFT  = ../
GENERIC= ../generics/includes/
HEADERS= ft_opencl.h
HEAD   = $(addprefix $(HEADERS), $(INCD))
INC    = -I$(INCD) -I$(GENERIC) -I$(LIBFT)

.PHONY : all clean

all : $(OBJS)

$(OBJD)%.o: $(SRCD)%.c
	@mkdir -p $(OBJD)
	gcc $(CFLG) $(INC) -c -o $@ $<

clean:
		@rm -f $(OBJS)
		@echo "printf objects cleaned"

re: clean all
