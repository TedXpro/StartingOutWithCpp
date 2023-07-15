output.exe: mathDemo.o MathStack.o
	g++ mathDemo.o MathStack.o -o output.exe

mathDemo.o: mathDemo.cpp
	g++ -c mathDemo.cpp

MathStack.o: MathStack.cpp MathStack.h
	g++ -c MathStack.cpp

clean:
	rm *.o output.exe