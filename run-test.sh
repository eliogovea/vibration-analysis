time ./gen_cos 1000 20 1000 > input.txt &
tail -f input.txt | ./vib
