#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#		<FILE>.o - Builds <FILE>.o object file [main.c, memory.c]
#		<FILE>.i - Builds <FILE>.i preprocessor file
#		<FILE>.asm - Builds <FILE>.asm assembly instructions file
#		compile-all - Builds object files from source files. DOES NOT LINK. Has PHONY proctection
#		build - Builds Executable 
#		clean - Removes ALL build outputs from previous builds[.o, .asm, .i, .map, .exe]		
#
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#		CPU= - Can be set to different ARM processors[cortex-m0plus,cortex-m4] 	
#		ARCH= - Can be set to different ARM architeture[arm7ve-m, thumb, etc]
#		SPECS= - Can be set different spec files [nosys.spec, nano.specs]
#
#------------------------------------------------------------------------------
include sources.mk

PLATFORM=HOST
GENERAL_FLAGS = -Wall -Werror -g  -O0 -std=c99
TARGET = c1m2
DEBUG = VERBOSE

ifeq ($(PLATFORM),HOST)
	CC := gcc
	SIZE = size
 else 
	CC  := arm-none-eabi-gcc
	SIZE := arm-none-eabi-size
	LINKER_FILE = -T, msp432p401r.lds
	CPU = cortex-m4
	ARCH= arm7ve-m
	PLATFORM_FLAGS = -mcpu=$(CPU) -march=$(ARCH) -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs 
endif

LDFLAGS := -Wl,-Map=$(TARGET).map $(LINKER_FILE)
CFLAGS := $(GENERAL_FLAGS) $(PLATFORM_FLAGS)
CPPFLAGS := -D$(PLATFORM) -D$(DEBUG) $(INCLUDES)

OBJS:= $(SOURCES:.c=.o)
ASMS:= $(SOURCES:.c=.asm)
DEPS = $(SOURCES:.c=.dep)
PPSR:= $(SOURCES:.c=.i)
MAPS:= $(SOURCES:.c=.map)

.PHONY : compile-all build clean

build: $(TARGET)

$(TARGET): $(OBJS) $(DEPS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

%.i: %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) -o $@


%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@


%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@


%.dep: %.c
	$(CC) -E -M $< $(CFLAGS) $(CPPFLAGS) -o $@


compile-all: $(OBJS)

.PHONY: clean

clean: 
    # This should remove all generated files.
	del -f $(TARGET).exe $(TARGET).map $(MAPS) $(OBJS) $(ASMS) $(PPSR) $(DEPS)



