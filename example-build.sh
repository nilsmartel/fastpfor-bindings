gcc example.c -l c-bridge -L ./cpp-lib/build
export LD_LIBRARY_PATH=./cpp-lib/build/:

echo running a.out
./a.out

echo done

# echo removing binary
# rm ./a.out
