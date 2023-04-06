output.exe: bank.o Account.o
	g++ bank.o Account.o -o output.exe

bank.o: bank.cpp
	g++ -c bank.cpp

Account.o: Account.cpp Account.h
	g++ -c Account.cpp

clean: 
	rm *.o output.exe