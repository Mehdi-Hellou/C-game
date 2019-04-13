CC = g++
CFLAGS = -Wall -g -O0 -std=c++11
INCLUDES = -I/usr/include/SDL2
LFLAGS = 
LIBS = -lSDL2_image -lSDL2main -lSDL2 -lSDL2_ttf

SRCS = sprite.cpp statBar.cpp texte.cpp hud.cpp perso.cpp humain.cpp mechant.cpp zombie.cpp robot.cpp magicien.cpp ninja.cpp partie.cpp menu.cpp controls.cpp ecranChoix.cpp interface.cpp main.cpp  
 
OBJS = $(SRCS:.cpp=.o)

MAIN = jeu

.PHONY: depend clean

all:    $(MAIN)
		@echo  Simple compiler named mycc has been compiled

$(MAIN): $(OBJS) 
		$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
		$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
		$(RM) *.o *~ $(MAIN)

depend: $(SRCS)
		makedepend $(INCLUDES) $^
