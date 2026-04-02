TARGET := rootbear
SOURCES := source

DEVKITPRO ?= /opt/devkitpro
DEVKITARM ?= $(DEVKITPRO)/devkitARM

include $(DEVKITARM)/base_rules

CFILES := $(wildcard $(SOURCES)/*.c)
OFILES := $(CFILES:.c=.o)

all: $(TARGET).gba

$(TARGET).gba: $(OFILES)
	$(CC) $(OFILES) -specs=gba.specs -o $(TARGET).elf -lgba
	$(OBJCOPY) -O binary $(TARGET).elf $(TARGET).gba
