#!/bin/bash


for a in 0 1 2 3 4 5 6
do
	echo $a;
	for i in 100000000 300000000 500000000 777000000 900000000
	do
		echo $i; { time ./lab1.$a.out $i >/dev/null; } 2>&1 | grep real
	done
	let a+=1	
done
