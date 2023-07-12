output.exe: mainDemo.o NumberList.o
	g++ mainDemo.o NumberList.o -o output.exe

mainDemo.o: mainDemo.cpp
	g++ -c mainDemo.cpp

NumberList.o: NumberList.cpp NumberList.h
	g++ -c NumberList.cpp

clean:
	rm *.o output.exe