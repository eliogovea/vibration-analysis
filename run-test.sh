time ./gen_cos 100 20 500 > input.txt &
tail -f input.txt | ./vib
