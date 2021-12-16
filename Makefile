all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	chmod a+x src/test.sh
	./src/test.sh

