# sources.mk
ifeq ($(PLATFORM), MSP432)
    SOURCES = src/main.c src/memory.c src/stats.c src/data.c src/course1.c \
              src/startup_msp432p401r_gcc.c src/system_msp432p401r.c src/interrupts_msp432p401r_gcc.c

    INCLUDES = -Iinclude/common -Iinclude/msp432 -Iinclude/CMSIS
else
    SOURCES = src/main.c src/memory.c src/stats.c src/data.c src/course1.c

    INCLUDES = -Iinclude/common
endif
