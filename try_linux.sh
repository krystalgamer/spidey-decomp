CXX=clang++ cmake -B out/clang
CXX=g++ cmake -B out/gcc

make -C out/clang clean
make -j12 -C out/clang
./out/clang/spider

make -C out/gcc clean
make -j12 -C out/gcc
./out/gcc/spider
