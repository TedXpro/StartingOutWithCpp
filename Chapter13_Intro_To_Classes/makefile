output.exe: practiceCode.o Rectangle.o
	g++ practiceCode.o Rectangle.o -o output.exe

practiceCode.o: practiceCode.cpp
	g++ -c practiceCode.cpp

Rectangle.o: Rectangle.cpp Rectangle.h
	g++ -c Rectangle.cpp

clean:
	rm *.o output.exe