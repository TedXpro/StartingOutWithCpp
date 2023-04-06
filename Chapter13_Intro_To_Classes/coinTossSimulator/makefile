output.exe: coinToss.o Coin.o
	g++ coinToss.o Coin.o -o output.exe

coinToss.o: coinToss.cpp
	g++ -c coinToss.cpp

coin.o: Coin.cpp Coin.h
	g++ Coin.cpp

clean: 
	rm *.o output.exe