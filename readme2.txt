Para MACOS

make distclean  
find . -name "*.o" -delete
find . -name "*.d" -delete
make -f Makefile_MacOS 