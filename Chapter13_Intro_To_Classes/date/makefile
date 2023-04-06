output.exe: displayDate.o Date.o
	g++ displayDate.o Date.o -o output.exe

displayDate.o: displayDate.cpp
	g++ -c displayDate.cpp

Date.o: Date.cpp Date.h
	g++ -c Date.cpp

clean: 
	rm *.o output.exe