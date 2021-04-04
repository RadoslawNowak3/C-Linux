SUFFIXES: .c .cpp .o .x .h
############################
DIR = `basename $(CURDIR)`
NAME1 = powielanie
NAME2 = sem
NAME3 = sekcja
############################
EXEC1  = $(NAME1).x  
OBJS1  = $(NAME1).o
OBJS2  = $(NAME2).o
EXEC3  = $(NAME3).x  
OBJS3  = $(NAME3).o
LIB_NAME = semlib
LIB_DIR = ./lib
LIB_SHAR = lib$(LIB_NAME).so
LIB_OBJS = $(OBJS2)	
HEADS2 = $(NAME2).h			
############################
############################
CFLAGS = -Wall -O -fPIC -pthread 
LFLAGS = -Wall -O -pthread
LDLIBS = -lm
CO = gcc
LD = $(CO)
AR = ar
ARFLAGS = rv
############################
%.o: %.c %.h
	$(CO) $(CFLAGS) -c $<
%.o: %.c
	$(CO) $(CFLAGS) -c $<
############################
.PHONY: all
all: $(EXEC1) $(EXEC3)
######################################## 
$(LIB_SHAR): $(LIB_OBJS) 
	$(LD) -shared -o $@ $(LFLAGS) $(LIB_OBJS)
	mkdir -p $(LIB_DIR)
	mv $(LIB_SHAR) $(LIB_DIR)
$(EXEC1): $(OBJS1)
$(OBJS1): $(HEADS2)
$(EXEC3): $(OBJS3) 
$(OBJS3): $(HEADS2)
#######################################
.PHONY: clean tar
clean:                                                     
	rm -f .o  *~ *.a *.so *.x core core a.out; rm -rf ${LIB_DIR}

tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
