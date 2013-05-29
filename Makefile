encoder.out : decoder.o encoder.o encoderRunner.o  
	g++ -ansi -Wall -g -o encoder.out decoder.o encoder.o encoderRunner.o  

decoder.o : decoder.cpp decoder.h 
	g++ -ansi -Wall -g -c -pg decoder.cpp

encoder.o : encoder.cpp encoder.h 
	g++ -ansi -Wall -g -c -pg encoder.cpp

encoderRunner.o : encoderRunner.cpp CPUTimer.h encoder.h decoder.h 
	g++ -ansi -Wall -g -c -pg encoderRunner.cpp

clean : 
	rm -f encoder.out decoder.o  encoder.o  encoderRunner.o   
