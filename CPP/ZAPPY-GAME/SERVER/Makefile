NAMESERV	= zappy_server

SRCSERV	=   server.c\
			CLIENTLIST/client.c\
			CLIENTLIST/commande.c\
			MAP/map.c\
			AI/AI.c\
			request.c\
			CMD/AI_Cmd.c\
			CMD/GUI_Cmd.c\
			CMD/Exec.c\
			CMD/Look.c\
			CMD/Broadcast.c\
			CMD/Eject.c\
			EQUIPE/equipe.c\
			EGG/egg.c\
			main.c


all:	$(NAMESERV)

$(NAMESERV) :
			gcc -o $(NAMESERV) $(SRCSERV) -luuid -g3 -lm

clean:
	rm		-rf		$(OBJ)

fclean:
	rm	 -rf 	$(NAMESERV)

re:		fclean all clean