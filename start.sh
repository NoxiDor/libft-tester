make -s -C ../
cc *.c -L../ -lft -I../ -lbsd
./a.out
rm -rf a.out
