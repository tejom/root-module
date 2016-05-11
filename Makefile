obj-m += root.o

all: remove install clean

build: 
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

install: build
	insmod $$PWD/root.ko

remove: 
	rmmod root

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

help:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) help
