time ./gen_cos 100 20 200 > input.txt &
tail -f input.txt | ./vib
