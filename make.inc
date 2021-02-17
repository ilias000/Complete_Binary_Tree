# This file is part of the binary_tree module.
#
# Anyone who wants to use the binary_tree module should include this file in their
# Makefile, so that compilation is configured properly
#
 
# Set compiler flags. -I... tells the compiler to look in our directory for
# include files, so that #include "binary_tree.h" works.
#
CFLAGS += -I$(MODULES)/complete_bt

OBJS += $(MODULES)/complete_bt/complete_bt.o

# needed to use the math library
LINKS += -lm

# We use the list module, include its make.inc so that it can configure itself.
#
include $(MODULES)/binary_tree/make.inc