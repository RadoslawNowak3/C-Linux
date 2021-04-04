.SUFFIXES: .c .cpp .o .x .h

DIR = `basename $(CURDIR)`
########################
NAME1 = obsluga
EXEC1  = $(NAME1).x 
OBJS1  = $(NAME1).o
LIBS1  = 
HEADS1 =
########################
CFLAGS = -Wall -O -fPIC
LFLAGS = -Wall -O
LDLIBS = -lm
CO = gcc
LD = $(CO)
AR = ar
ARFLAGS = rv
#-------------------------------------------------
%.o: %.c
	$(CO) $(CFLAGS) -c $<
#-------------------------------------------------
.PHONY: all
all: $(EXEC1)
##################################################
$(EXEC1): $(OBJS1) $(LIBS1) 
	$(LD) -o $@ $(LFLAGS) $^
.PHONY: run1
run1: $(EXEC1)
	./$(EXEC1)
##################################################
$(EXEC2): $(OBJS2) $(LIBS2) 
	$(LD) -o $@ $(LFLAGS) $^
.PHONY: run2
run3: $(EXEC2) $(EXEC1)
	./$(EXEC2) $(EXEC1)
# Sprzataczka (tez "phony target")
######################################################################
.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}
# Archiwizacja i kompresja
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
