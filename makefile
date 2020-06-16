obj:=$(patsubst %.c, %.o, $(wildcard *.c))

apc.exe: $(obj)
	gcc -o $@ $^
clean:
	rm *.o *.exe

