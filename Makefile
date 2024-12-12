all: run

finish:main.o general_algo.o elliptic_curve.o rsa.o attacking_algo.o
	g++ main.o general_algo.o elliptic_curve.o rsa.o attacking_algo.o -lntl -lgmp -pthread -o finish

main.o: main.cpp
	g++ -c main.cpp -o main.o

general_algo.o: general_algo.cpp
	g++ -c general_algo.cpp -o general_algo.o

elliptic_curve.o: elliptic_curve.cpp
	g++ -c elliptic_curve.cpp -o elliptic_curve.o

rsa.o: rsa.cpp
	g++ -c rsa.cpp -o rsa.o

attacking_algo.o: attacking_algo.cpp
	g++ -c attacking_algo.cpp -o attacking_algo.o

header: crypto.h
	g++ crypto.h

clear: 
	rm *.o finish

run: finish
	./finish
