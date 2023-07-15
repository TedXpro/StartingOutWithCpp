output.exe: mainDemo.o LinkedList.o
	g++ mainDemo.o LinkedList.o -o output.exe

mainDemo.o: mainDemo.cpp
	g++ -c mainDemo.cpp

LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c LinkedList.cpp

clean:
	rm *.o output.exe