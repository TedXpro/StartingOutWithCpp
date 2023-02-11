output.exe: kebele.o Queue.o
	g++ kebele.o Queue.o -o output.exe

kebele.o: kebele.cpp
	g++ -c kebele.cpp

Queue.o: Queue.cpp Queue.h
	g++ -c Queue.cpp

clean: 
	rm *.o output.exe