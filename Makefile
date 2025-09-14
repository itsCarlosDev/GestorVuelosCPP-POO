########################################################################
####################### Makefile Template ##############################
########################################################################

# Compiler settings - Can be customized.
CC = g++
CXXFLAGS = -g -std=c++14 -Wall # Universidad utiliza compilador ver.14
LDFLAGS =

# Makefile settings - Can be customized.
APPNAME = main.exe
EXT = .cpp
SRCDIR = src
OBJDIR = obj
DEPDIR = dep
HDRDIR = $(SRCDIR)/headers
INCLUDES = -I$(HDRDIR)

############## Do not change anything from here downwards! #############
SRC = $(wildcard $(SRCDIR)/*$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=$(DEPDIR)/%.d)

# UNIX-based OS variables & settings
RM = rm
DELOBJ = $(OBJ)
# Windows OS variables & settings
DEL = del
EXE = .exe
WDELOBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)\\%.o)
WDELDEP = $(SRC:$(SRCDIR)/%$(EXT)=$(DEPDIR)\\%.d)

########################################################################
####################### Targets beginning here #########################
########################################################################

all: $(APPNAME)

# Builds the app
$(APPNAME): $(OBJ) | dirs
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Creates the dependecy rules
$(DEPDIR)/%.d: $(SRCDIR)/%$(EXT) | dirs
	@$(CC) $(CXXFLAGS) $(INCLUDES) $< -MM -MT $(@:$(DEPDIR)/%.d=$(OBJDIR)/%.o) > $@

# Includes all .h files
-include $(DEP)

# Building rule for .o files and its .c/.cpp in combination with all .h
$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT) | dirs
	$(CC) $(CXXFLAGS) $(INCLUDES) -o $@ -c $<

.PHONY: dirs
ifeq ($(OS),Windows_NT)
dirs:
	@if not exist "$(OBJDIR)" mkdir "$(OBJDIR)"
	@if not exist "$(DEPDIR)" mkdir "$(DEPDIR)"
else
dirs:
	@mkdir -p $(OBJDIR) $(DEPDIR)
endif

################### Cleaning rules for Unix-based OS ###################
# Cleans complete project
.PHONY: clean
clean:
	$(RM) $(DELOBJ) $(DEP) $(APPNAME)

# Cleans only all files with the extension .d
.PHONY: cleandep
cleandep:
	$(RM) $(DEP)

#################### Cleaning rules for Windows OS #####################
# Cleans complete project
.PHONY: cleanw
cleanw:
	$(DEL) $(WDELOBJ) $(WDELDEP) $(APPNAME)

# Cleans only all files with the extension .d
.PHONY: cleandepw
cleandepw:
	$(DEL) $(WDELDEP)
