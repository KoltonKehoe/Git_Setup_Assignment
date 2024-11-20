all: xmlReader.exe

xmlReader.exe: xmlReader.o

	gcc -o xmlReader.exe xmlReader.o

xmlReader.o: xmlReader.c

	gcc -c xmlReader.c

clean:

	rm xmlReader.o xmlReader.exe
