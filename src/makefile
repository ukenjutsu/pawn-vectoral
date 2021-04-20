GPP=g++
GCC=gcc

OUTFILE="plugins/CVector.so"

COMPILE_FLAGS=-c -O3 -w -DLINUX -I./SDK/amx/

all:
	$(GCC) $(COMPILE_FLAGS) ./SDK/amx/*.c
	$(GPP) $(COMPILE_FLAGS) ./SDK/*.cpp
	$(GPP) $(COMPILE_FLAGS) ./*.cpp
	$(GPP) -O3 -fshort-wchar -shared -o $(OUTFILE) *.o
	rm -f *.o