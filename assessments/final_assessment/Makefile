#******************************************************************************
# Copyright (C) 2021 by Josh Illes
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Josh Illes is not liable for any misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here>
#
#------------------------------------------------------------------------------

SHELL=/bin/bash

# Include the sources.mk for platform-specific sources and includes
include sources.mk

# Platform Overrides
PLATFORM=HOST

# Compile time switches
COURSE1=false
VERBOSE=false

# General Flags for all platforms
GEN_FLAGS = -Wall \
            -g \
            -O0 \
            -std=c99

TARGET = final_assesment

# Platform Dependant Variables
ifeq ($(PLATFORM),MSP432)
	# MSP432 dependent build options
	CPU = cortex-m4
	ARCH = armv7e-m

	# Compiler
	CC = arm-none-eabi-gcc

	# Linker
	LD = arm-none-eabi-ld
	SIZE = arm-none-eabi-size

	# Linker Flags
	LINKER_FILE = ../msp432p401r.lds
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE) -lm
	
	# Compiler Flags
	CFLAGS = 	$(GEN_FLAGS) \
				-mcpu=$(CPU) \
				-mthumb \
				-march=$(ARCH) \
				-mfloat-abi=hard \
				-mfpu=fpv4-sp-d16\
				--specs=nosys.specs
	CPPFLAGS = -DMSP432 $(INCLUDES)

else
	# @echo Host platform detected
	CC = gcc
	CFLAGS = $(GEN_FLAGS)
	CPPFLAGS = -DHOST $(INCLUDES)
	SIZE = size
	LDFLAGS = -lm
endif

# IF COURSE1 is defined, add a flag
ifeq ($(COURSE1), true)
	CPPFLAGS += -DCOURSE1
endif

# IF VERBOSE is defined, add a flag
ifeq ($(VERBOSE), true)
	CPPFLAGS += -DVERBOSE
endif

PREP = $(SOURCES:.c=.i)	# Preprocessor Files
DEPS = $(SOURCES:.c=.d)	# Dependency Files
ASMS = $(SOURCES:.c=.asm)	# Assembly Files
OBJS = $(SOURCES:.c=.o)	# Object files

#-------------------------------------------------------------------------------
# Target: compile-all
# Compiles all object files without linking
#-------------------------------------------------------------------------------
.PHONY: compile-all
compile-all: $(OBJS)
	@echo "All object files compiled."

#-------------------------------------------------------------------------------
# Target: build
# Links all object files into a final executable (final_assesment.out)
#-------------------------------------------------------------------------------
.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	@echo "Build complete. Output: $@"
	@size $@

#-------------------------------------------------------------------------------
# Target: clean
# Removes all generated files
#-------------------------------------------------------------------------------
.PHONY: clean
clean:
	rm -f ${SRC_DIR}/*{.o,.out,.map,.asm,.i} $(TARGET).out $(DEPS)
	@echo "Build artifacts cleaned."

#-------------------------------------------------------------------------------
# Target: run
# Builds and runs the project
#-------------------------------------------------------------------------------
.PHONY: run
run: $(TARGET).out
	./$(TARGET).out
