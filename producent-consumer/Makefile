SUFFIXES: .c .cpp .o .x .h
############################
DIR = `basename $(CURDIR)`
############################
NAME1 = fifo
EXEC1  = $(NAME1).x  
OBJS1  = $(NAME1).o
LIBS1  = 
HEADS1 = 
############################
NAME2 = producent
EXEC2  = $(NAME2).x  
OBJS2  = $(NAME2).o
LIBS2  = 
HEADS2 = 
############################
NAME3 = konsument
EXEC3  = $(NAME3).x  
OBJS3  = $(NAME3).o
LIBS3  = 
HEADS3 = 
############################
CFLAGS = -Wall -O -fPIC
LFLAGS = -Wall -O
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
all: $(EXEC1)
######################################## 

$(EXEC1): $(OBJS1) $(LIBS1) 
	$(LD) -o $@ $(LFLAGS) $^
.PHONY: run1
run1: $(EXEC1)
	./$(EXEC1)
########################################
$(EXEC2): $(OBJS2) $(LIBS2) 
	$(LD) -o $@ $(LFLAGS) $^
$(EXEC3): $(OBJS3) $(LIBS3) 
	$(LD) -o $@ $(LFLAGS) $^
#######################################
.PHONY: clean tar
clean:                                                     
	rm -f .o  *~ *.a *.so *.x core core a.out; rm -rf ${LIB_DIR}

tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
