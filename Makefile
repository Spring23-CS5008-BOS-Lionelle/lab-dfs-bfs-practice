CC=clang
CFLAGS=-Wall 

all: myprogram

myprogram: printer.c
	$(CC) $(CFLAGS) -o dfs_print.out printer.c 

clean:
	rm -f *.out