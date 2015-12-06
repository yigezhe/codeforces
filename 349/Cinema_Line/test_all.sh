#超时的也可以快速得到答案？
for i in 1 2 3 4
do
	./a.out < in$i >tmp$i
       	diff -c out$i tmp$i
	if [ $? -eq 0 ]
	then
		echo "$i is ok\n"
       	else
		echo "$i is wrong\n"
       	fi
done
