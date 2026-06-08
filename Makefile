all:
	/c/Users/LENOVO/Downloads/winlibs-x86_64-posix-seh-gcc-16.1.0-mingw-w64msvcrt-14.0.0-r2/mingw64/bin/gcc main.c tableau_statique.c patient.c consultation.c -o test

clean:
	rm -f test