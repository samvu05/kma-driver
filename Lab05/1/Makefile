KDIR = /lib/modules/`uname -r`/build

all:
	make -C $(KDIR) M=`pwd`
	gcc -o app test.c

clean:
	make -C $(KDIR) M=`pwd` clean
	rm -rf app
