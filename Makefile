CC=clang   # This variable is which compiler to use, we will use the variable later by $(CC)
CFLAGS=-Wall  # this variable is command line arguments

all: myprogram  #runs target myprogram is nothing is passed into make

myprogram: printer.c  # this is the target, and the dependency
	$(CC) $(CFLAGS) -o dfs_print.out printer.c  

clean: #this is a clean target, it removes all the .out files, called via > make clean
	rm -f *.out