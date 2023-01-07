output.exe: findPrime.o Prime.o
	g++ findPrime.o Prime.o -o output.exe

findPrime.o: findPrime.cpp
	g++ -c findPrime.cpp

Prime.o: Prime.cpp Prime.h
	g++ -c Prime.cpp

clean: 
	rm *.o output
