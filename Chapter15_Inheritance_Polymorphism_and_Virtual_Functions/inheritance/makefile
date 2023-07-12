output.exe: Grade.o FinalExam.o
	g++ FinalExam.o -o output.exe

FinalExam.o: FinalExam.cpp Final.o
	g++ -c Final.cpp

Final.o: Final.cpp Final.o Grade.o
	g++ -c Final.cpp

Grade.o: Grade.cpp Grade.o
	g++ -c Grade.cpp

clean: 
	rm .*o output.exe