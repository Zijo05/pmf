// Kreiranje .o filova te linkanje .o filova u .exe faile to pokretanje .exe filea
g++ -c p1.cpp p2.cpp ; g++ p1.o p2.o -o kombinovano.exe; .\kombinovano.exe

// Kreiranje staticke biblioteke
g++ -c p1.cpp p3.cpp ; g++ p1.o p2.o p3.o -o kombinovano.exe; .\kombinovano.exe

// Kreiranje i koristenje .lib (kod mene .a)
ar rcs mojalib.a p1.o p2.o p3.o ; g++ mojalib.a -o kombinovanolib.exe ; ./kombinovanolib.exe

// Kreiranje i koristenje .dll
g++ p1.cpp -L. -lmylibrary -o kombinobanodll.exe ; g++ p1.cpp -L. -lmylibrary -o kombinobanodll.exe ; ./kombinovanodll.exe 