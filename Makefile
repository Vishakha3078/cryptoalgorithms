all: finish

finish:main.o brutef_dlp.o diff_hellencryption.o diff_helldecryption.o elgamal_encryption.o elgamal_decryption.o dig_sign.o dig_signverification.o build_h.o elliptic_curve.o
	g++ main.o brutef_dlp.o diff_hellencryption.o diff_helldecryption.o elgamal_encryption.o elgamal_decryption.o dig_sign.o dig_signverification.o build_h.o elliptic_curve.o -lntl -lgmp -pthread -o finish

main.o: main.cpp
	g++ -c main.cpp -o main.o

brutef_dlp.o: brutef_dlp.cpp
	g++ -c brutef_dlp.cpp -o brutef_dlp.o

diff_hellencryption.o: diff_hellencryption.cpp
	g++ -c diff_hellencryption.cpp -o diff_hellencryption.o

diff_helldecryption.o: diff_helldecryption.cpp
	g++ -c diff_helldecryption.cpp -o diff_helldecryption.o

elgamal_encryption.o: elgamal_encryption.cpp
	g++ -c elgamal_encryption.cpp -o elgamal_encryption.o

elgamal_decryption.o: elgamal_decryption.cpp
	g++ -c elgamal_decryption.cpp -o elgamal_decryption.o
  
dig_sign.o: dig_sign.cpp
	g++ -c dig_sign.cpp -o dig_sign.o

dig_signverification.o: dig_signverification.cpp
	g++ -c dig_signverification.cpp -o dig_signverification.o

build_h.o: build_h.cpp
	g++ -c build_h.cpp -o build_h.o

elliptic_curve.o: elliptic_curve.cpp
	g++ -c elliptic_curve.cpp -o elliptic_curve.o

header: crypto.h
	g++ crypto.h

clear: 
	rm *.o finish

run: 
	./finish
