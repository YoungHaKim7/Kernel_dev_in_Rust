# Kernel Module Makefile
# This Makefile handles Linux kernel module compilation

# Module object name
obj-m += hello.o

# Map hello.o to src/main.c (hello.o will be built from main.o in src directory)
hello-objs := src/main.o

# Kernel build directory
KDIR := /lib/modules/$(shell uname -r)/build

# Current directory
PWD := $(shell pwd)

# Default target: build the kernel module
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

# Clean build artifacts
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	rm -f Module.symvers modules.order

# Install module (requires root)
install:
	$(MAKE) -C $(KDIR) M=$(PWD) modules_install

# Load module
load:
	sudo insmod hello.ko

# Unload module
unload:
	sudo rmmod hello

# Reload module (unload then load)
reload: unload load

# Show kernel logs
log:
	dmesg | tail -20

# Show module-specific logs
log-module:
	dmesg | grep -i hello | tail -20

# Help information
help:
	@echo "Kernel Module Makefile"
	@echo ""
	@echo "Available targets:"
	@echo "  make all         - Build the kernel module"
	@echo "  make clean      - Clean build artifacts"
	@echo "  make install    - Install the module (requires root)"
	@echo "  make load       - Load the module (requires sudo)"
	@echo "  make unload     - Unload the module (requires sudo)"
	@echo "  make reload     - Reload the module"
	@echo "  make log        - Show recent kernel logs"
	@echo "  make log-module - Show module-specific logs"
	@echo "  make help       - Show this help message"

.PHONY: all clean install load unload reload log log-module help
