##
## EPITECH PROJECT, 2022
## my_FTP
## File description:
## Makefile
##

NAMESERV	= myteams_server
NAMECLI 	= myteams_cli

SRCSERV	=   SERVER/*.c \
			SERVER/INIT/*.c \
			SERVER/cmd/*.c \
			SERVER/Channel/channel.c \
			SERVER/Team/team.c \
			SERVER/User/user.c \
			SERVER/Save/*.c \
			SERVER/Messages/*.c

SRCCLI =   CLIENT/*.c\
			  CLIENT/ERROR_HANDLER/*.c	\
			  CLIENT/Answer/*.c

all:	$(NAMESERV) $(NAMECLI)

$(NAMESERV) :
			gcc -o $(NAMESERV) $(SRCSERV) -Llibs/myteams/ -lmyteams -luuid -g3
$(NAMECLI) :
			gcc -o $(NAMECLI) $(SRCCLI) -Llibs/myteams/ -lmyteams -luuid -g3

clean:
	rm		-rf		$(OBJ)

fclean:
	rm	 -rf 	$(NAMESERV) $(NAMECLI)

re:		fclean all clean
