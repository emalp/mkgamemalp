CC = g++
CFLAGS = -c -Wall -IHeaders 
NAME = MKGAMEMALP

mkgamemalp: main.o MKGame.o Board.o Player.o ComputerPlayer.o HumanPlayer.o Driver.o AI.o
	$(CC) main.o MKGame.o Board.o Player.o ComputerPlayer.o HumanPlayer.o Driver.o AI.o -o $(NAME)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

MKGame.o : MKGame.cpp Headers/MKGame.h
	$(CC) $(CFLAGS) MKGame.cpp

Board.o: Board.cpp Headers/Board.h
	$(CC) $(CFLAGS) Board.cpp

Player.o: Player.cpp Headers/Player.h
	$(CC) $(CFLAGS) Player.cpp

ComputerPlayer.o: ComputerPlayer.cpp Headers/ComputerPlayer.h
	$(CC) $(CFLAGS) ComputerPlayer.cpp

HumanPlayer.o: HumanPlayer.cpp Headers/HumanPlayer.h
	$(CC) $(CFLAGS) HumanPlayer.cpp

AI.o: AI.cpp
	$(CC) $(CFLAGS) AI.cpp

Driver.o: Driver.cpp
	$(CC) $(CFLAGS) Driver.cpp
	
clean:
	rm *.o mkgamemalp
