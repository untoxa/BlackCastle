SHELL := /bin/bash

# If you move this project you can change the directory
# to match your GBDK root directory (ex: GBDK_HOME = "C:/GBDK/"
ifndef GBDK_HOME
GBDK_HOME = ../../gbdk-2020/build/gbdk/
endif
LCC = $(GBDK_HOME)bin/lcc

# Set platforms to build here, spaced separated. (These are in the separate Makefile.targets)
# They can also be built/cleaned individually: "make gg" and "make gg-clean"
# Possible are: gb gbc pocket sms gg
TARGETS=nes gb megaduck gg sms pocket

# Configure platform specific LCC flags here:
LCCFLAGS_gb      = -Wl-yt0x19 -Wm-yn"$(PROJECTNAME)"
LCCFLAGS_pocket  = -Wl-yt0x19 -Wm-yn"$(PROJECTNAME)"
LCCFLAGS_duck    = -Wl-yt0x19 -Wm-yn"$(PROJECTNAME)"
LCCFLAGS_sms     = 
LCCFLAGS_gg      =
LCCFLAGS_nes     = -Wb-min=0

LCCFLAGS += $(LCCFLAGS_$(EXT)) # This adds the current platform specific LCC Flags

LCCFLAGS += -Wl-j -Wm-yoA -autobank -Wb-ext=.rel # MBC + Autobanking related flags
LCCFLAGS += -Wl-j -Wl-w -Wm-yS
# LCCFLAGS += -debug      # Uncomment to enable debug output
LCCFLAGS += -v -Wb-v    # Uncomment for lcc verbose output#
LCCFLAGS += -Wa-l -Wl-u

CFLAGS   = -Wf-Iinclude -Wf-MMD
#CFLAGS   += -Wf'--max-allocs-per-node 50000'

# You can set the name of the ROM file here
PROJECTNAME = blackcastle

# EXT?=gb # Only sets extension to default (game boy .gb) if not populated
SRCDIR      = src
SRCPLAT     = src/$(PORT)
OBJDIR      = obj/$(EXT)
RESDIR      = res
BINDIR      = build/$(EXT)
MKDIRS      = $(OBJDIR) $(BINDIR) # See bottom of Makefile for directory auto-creation

BINS	    = $(OBJDIR)/$(PROJECTNAME).$(EXT)
CSOURCES    = $(foreach dir,$(SRCDIR),$(notdir $(wildcard $(dir)/*.c))) $(foreach dir,$(SRCPLAT),$(notdir $(wildcard $(dir)/*.c))) $(foreach dir,$(RESDIR),$(notdir $(wildcard $(dir)/*.c)))
ASMSOURCES  = $(foreach dir,$(SRCDIR),$(notdir $(wildcard $(dir)/*.s))) $(foreach dir,$(SRCPLAT),$(notdir $(wildcard $(dir)/*.s)))
OBJS        = $(CSOURCES:%.c=$(OBJDIR)/%.o) $(ASMSOURCES:%.s=$(OBJDIR)/%.o)

# Dependencies
DEPS = $(OBJS:%.o=%.d)

-include $(DEPS)

# Builds all targets sequentially
all: $(TARGETS)

# Compile .c files in "src/" to .o object files
$(OBJDIR)/%.o:	$(SRCDIR)/%.c
	$(LCC) $(CFLAGS) -c -o $@ $<

# Compile .c files in "src/<target>/" to .o object files
$(OBJDIR)/%.o:	$(SRCPLAT)/%.c
	$(LCC) $(CFLAGS) -c -o $@ $<

# Compile .c files in "res/" to .o object files
$(OBJDIR)/%.o:	$(RESDIR)/%.c
	$(LCC) $(CFLAGS) -c -o $@ $<

# Compile .s assembly files in "src/<target>/" to .o object files
$(OBJDIR)/%.o:	$(SRCPLAT)/%.s
	$(LCC) $(LCCFLAGS) $(CFLAGS) -c -o $@ $<

# Compile .s assembly files in "src/" to .o object files
$(OBJDIR)/%.o:	$(SRCDIR)/%.s
	$(LCC) $(LCCFLAGS) $(CFLAGS) -c -o $@ $<

# If needed, compile .c files i n"src/" to .s assembly files
# (not required if .c is compiled directly to .o)
$(OBJDIR)/%.s:	$(SRCDIR)/%.c
	$(LCC) $(CFLAGS) -S -o $@ $<

# Link the compiled object files into a .gb ROM file
$(BINS):	$(OBJS)
	$(LCC) $(LCCFLAGS) $(CFLAGS) -o $(BINDIR)/$(PROJECTNAME).$(EXT) $(OBJS)

clean:
	@echo Cleaning
	@for target in $(TARGETS); do \
		$(MAKE) $$target-clean; \
	done

# Include available build targets
include Makefile.targets


# create necessary directories after Makefile is parsed but before build
# info prevents the command from being pasted into the makefile
ifneq ($(strip $(EXT)),)           # Only make the directories if EXT has been set by a target
$(info $(shell mkdir -p $(MKDIRS)))
endif
