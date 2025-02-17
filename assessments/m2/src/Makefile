# Makefile
include sources.mk

# Platform Overrides
PLATFORM ?= HOST
BASENAME = c1m2

# Architectures Specific Flags
ifeq ($(PLATFORM), MSP432)
    LINKER_FILE = -T ../msp432p401r.lds
    CPU = cortex-m4
    ARCH = armv7e-m
    SPECS = nosys.specs
else
    CPU = x86_64
    ARCH = $(shell arch)
endif

# Compiler Flags and Defines
ifeq ($(PLATFORM), MSP432)
    CC = arm-none-eabi-gcc
    LD = arm-none-eabi-ld
    LDFLAGS = -Wl,-Map=$(BASENAME).map $(LINKER_FILE)
    CFLAGS = -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mthumb -Wall -Werror -O0 -g -std=c99
    CPPFLAGS = -M -MF
    DEFINEFLAG = -DMSP432
else
    CC = gcc
    LDFLAGS = -Wl,-Map=$(BASENAME).map
    CFLAGS = -Wall -Werror -O0 -g -std=c99
    CPPFLAGS = -M -MF
    DEFINEFLAG = -DHOST
endif

# Object files, Assembly files, Preprocessed files, and Output executable
OBJS = $(SOURCES:.c=.o)
ASMS = $(SOURCES:.c=.s)
PPS = $(SOURCES:.c=.i)
OUTPUT = $(BASENAME).out

#-------------------------------------------------------------------------------
# Target: <file>.i
# Generates the preprocessed output of all C files
#-------------------------------------------------------------------------------
%.i: %.c
	$(CC) $(DEFINEFLAG) $(CFLAGS) $(INCLUDES) -E -o $@ $<
	$(CC) $(DEFINEFLAG) $(CFLAGS) $(INCLUDES) -M -MF $(basename $@).d $<

#-------------------------------------------------------------------------------
# Target: <file>.asm
# Generates assembly output of C files
#-------------------------------------------------------------------------------
%.asm: %.c
	$(CC) $(DEFINEFLAG) $(CFLAGS) $(INCLUDES) -S -o $@ $<

#-------------------------------------------------------------------------------
# Target: <file>.o
# Generates object files for all C files
#-------------------------------------------------------------------------------
%.o: %.c
	$(CC) $(DEFINEFLAG) $(CFLAGS) $(INCLUDES) -c -o $@ $<

#-------------------------------------------------------------------------------
# Target: compile-all
# Compiles all object files without linking
#-------------------------------------------------------------------------------
.PHONY: compile-all
compile-all: $(OBJS)
	@echo "All object files compiled."

#-------------------------------------------------------------------------------
# Target: build
# Links all object files into a final executable (c1m2.out)
#-------------------------------------------------------------------------------
.PHONY: build
build: $(OUTPUT)

$(OUTPUT): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@
	@echo "Build complete. Output: $@"
	@size $@

#-------------------------------------------------------------------------------
# Target: clean
# Removes all generated files
#-------------------------------------------------------------------------------
.PHONY: clean
clean:
	rm -f $(OBJS) $(ASMS) $(PPS) $(OUTPUT) $(BASENAME).map *.d
	@echo "Build artifacts cleaned."