output.exe: stackCode.o
	g++ stackCode.o -o output.exe

stackCode.o: stackCode.cpp
	g++ -c stackCode.cpp

clean: 
	rm *.o output.exe