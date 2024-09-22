all: finish

finish:main.o brutef_dlp.o diff_hellencryption.o diff_helldecryption.o el_gamal.o dig_sign.o 
	g++ main.o brutef_dlp.o diff_hellencryption.o diff_helldecryption.o el_gamal.o dig_sign.o -lntl -lgmp -pthread -o finish

main.o: main.cpp
	g++ -c main.cpp -o main.o

brutef_dlp.o: brutef_dlp.cpp
	g++ -c brutef_dlp.cpp -o brutef_dlp.o

diff_hellencryption.o: diff_hellencryption.cpp
	g++ -c diff_hellencryption.cpp -o diff_hellencryption.o

diff_helldecryption.o: diff_helldecryption.cpp
	g++ -c diff_helldecryption.cpp -o diff_helldecryption.o

el_gamal.o: el_gamal.cpp
	g++ -c el_gamal.cpp -o el_gamal.o
  
dig_sign.o: dig_sign.cpp
	g++ -c dig_sign.cpp -o dig_sign.o

header: crypto.h
	g++ crypto.h

clear: 
	rm *.o finish

run: 
	./finish
