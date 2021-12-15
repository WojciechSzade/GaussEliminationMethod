all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A0 dane/b0
	bin/gauss dane/A1 dane/b1
	bin/gauss dane/A2 dane/b2
	bin/gauss dane/A3 dane/b3
	bin/gauss dane/A4 dane/b4
	bin/gauss dane/A5 dane/b5
	bin/gauss dane/A6 dane/b6
	bin/gauss dane/A7 dane/b7
	bin/gauss dane/A8 dane/b8
	bin/gauss dane/A9 dane/b9
