#!/bin/bash
fails=0
for i in {0..10}
do
	./bin/gauss ./dane/A$i ./dane/b$i > ./dane/output.out
	DIFF=$(diff -w ./dane/output.out ./dane/odp$i)
	if [ "$DIFF" != "" ] 
	then
		fails=fails+1;
		echo ------------------test $i failed-------------------
		echo "output:"
		cat ./dane/output.out
		echo "expected:"
		cat ./dane/odp$i
		echo  --------------------------------------------------
	fi
done
if [ $fails == 0 ] 
then
	echo All tests passed!
fi
$SHELL
