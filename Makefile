obj-m := hello.o
obj-m += char_dev_drv.o
obj-m += klist.o
KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

default:
		$(MAKE) -C $(KDIR) SUBDIRS=$(PWD)