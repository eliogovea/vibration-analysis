time ./gen_cos 1000 20 100 > input.txt &
tail -f input.txt | ./vib
