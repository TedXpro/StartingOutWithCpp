output.exe: choHan.o Dealer.o Player.o 
	g++ choHan.o Dealer.o Player.o -o output.exe

choHan.o: choHan.cpp Dealer.o Player.o 
	g++ -c choHan.cpp

Dealer.o: Dealer.cpp Die.o Player.o
	g++ -c Dealer.cpp

Die.o: Die.cpp
	g++ -c Die.cpp

Player.o: Player.cpp
	g++ -c Player.cpp

clean: 
	rm .*o output.exe