# Zdroj informaci o Makefile: http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

# POVOLENE PRIKAZY:
	# rm, gcc, g++, mkdir, doxygen, cp, mv, cd, tar, make.

# KONSTANTY:
#	$@ = leva strana od :
#	$^ = prava strana od :
#	$< = 1. item z listu zavislosti
#	wildcard - vysledkem je odradkovany seznam podle patternu
#	notdir - z cesty vrati pouze konecny soubor, napr. src/a.cpp = vysledek je a.cpp
#	dir - z cesty vrati pouze cestu bez konecneho souboru, napr. src/a.cpp = vysledek je src/
#----------------------------------------------------------

# Pokud je upraven pouze *.h, makefile to nezjisti.

## vlozi vygenerovane zavislosti
-include $(DEP_FILE)

VERSION = 1.8
NAME = budikpet
DEP_FILE = dep.list
DOX_FILE = Doxyfile

ARCH_DIR = Archives
OBJ_DIR = obj
SRC_DIR = src
RES_DIR = res
DOC_DIR = doc

#LFLAGS = -std=c++11 -lncurses 
LFLAGS = -Wall -pedantic -Wno-long-long -O0 -ggdb -std=c++11 -lncurses
CFLAGS = $(LFLAGS) -c
CC = g++

# Jmena zdrojovych souboru
CPP_FILES = $(foreach dir, $(SRC_DIR), $(notdir $(wildcard $(dir)/*.cpp)))
OBJ_FILES = $(CPP_FILES:.cpp=.o)	# Vymeni koncovku
OBJ_PATH = $(patsubst %, $(OBJ_DIR)/%, $(OBJ_FILES))	# Kazdy .o soubor je opatren svoji cestou
#------------------------------------------------------------------------------------------------

# Startovaci pravidlo
compile: $(DEP_FILE) $(NAME)

# Univerzalni pravidlo pro generovani vsech objektovych souboru
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $< -o $@
#--------------------------------------------------------------

# Linkovani vsech objektovych souboru do jednoho spustitelneho programu.
$(NAME): $(OBJ_PATH)
	$(CC)  $^ $(LFLAGS) -o $@
#-----------------------------------------------------------------------


# Automaticke generovani zavislosti, priprava dulezitych slozek
$(DEP_FILE) dep:
	if ! [ -d $(OBJ_DIR) ]; then mkdir $(OBJ_DIR); fi;
	if ! [ -d $(SRC_DIR) ]; then mkdir $(SRC_DIR); fi;
	if ! [ -d $(DOC_DIR) ]; then mkdir $(DOC_DIR); fi;
	if ! [ -d $(RES_DIR) ]; then mkdir $(RES_DIR); fi;
	$(CC) -MM $(SRC_DIR)/*.cpp > $(DEP_FILE)
#-----------------------------------------------------------------------


################### POMOCNE FCE ######################
.PHONY: purge clean
purge clean:
	if [ -d $(OBJ_DIR) ]; then rm -rf $(NAME) $(DEP_FILE) $(OBJ_DIR); fi;
	if [ -d $(DOC_DIR) ]; then rm -rf $(DOC_DIR); fi;

run:
	./$(NAME)

valgrind:
	valgrind ./$(NAME) >/dev/null

debug:
	gdb ./$(NAME)

tar: clean
	if ! [ -d $(ARCH_DIR) ]; then mkdir $(ARCH_DIR); fi;
	tar --exclude=$(ARCH_DIR) -czf "$(NAME)_$(VERSION).zip" ../.
	mv "$(NAME)_$(VERSION).zip" "./$(ARCH_DIR)"

.PHONY: doc
doc:
	if ! [ -d $(DOC_DIR) ]; then mkdir $(DOC_DIR); fi;
	if ! [ -f "$(RES_DIR)/$(DOX_FILE)" ]; then doxygen -g "$(RES_DIR)/$(DOX_FILE)"; echo "Doxygen config created in $(RES_DIR)/$(DOX_FILE). Need to edit it!"; exit 1; fi;
	doxygen "$(RES_DIR)/$(DOX_FILE)"
