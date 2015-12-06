for i in 1 2 3 4 11 12 13 14 15 21 22 23 24 25 26 27 28 29 31 32 33 34 35 36
do
	./a.out < in$i >tmp$i
	diff -c out$i tmp$i
	if [ $? -eq 0 ]
	then
		echo "$i is ok"
	else
		echo "$i is wrong"
	fi
done
