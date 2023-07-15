output.exe: IntStack.o stackMain.o
	g++ IntStack.o stackMain.o -o output.exe

IntStack.o: IntStack.cpp IntStack.h
	g++ -c IntStack.cpp

stackMain.o: stackMain.cpp
	g++ -c stackMain.cpp

clean:
	rm *.o output.exe