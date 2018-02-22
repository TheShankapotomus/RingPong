TARGET   = ring-pong

CC       = gcc
# compiling flags here
CFLAGS   = -std=c99 -Wall -I. -g

LINKER   = gcc
# linking flags here
LFLAGS   = -Wall -I. -lm -g

SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

$(BINDIR)/$(TARGET): $(OBJECTS)
		@$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
		@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
		@$(CC) $(CFLAGS) -c $< -o $@
		@echo "Compilation successful!"

.PHONY: clean
clean:
		rm -rf $(OBJECTS)
		@echo "Cleanup complete!"

.PHONY: remove
remove: clean
		rm -rf $(BINDIR)/$(TARGET)
		@echo "Executable removed!"
