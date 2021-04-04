SUFFIXES: .c .cpp .o .x .h
################################
NAME1 = potokinie
EXEC1  = $(NAME1).x  
OBJS1  = $(NAME1).o
LIBS1  = 
HEADS1 = 
################################
CFLAGS = -Wall -O -fPIC
LFLAGS = -Wall -O
LDLIBS = -lm
CO = gcc
LD = $(CO)
AR = ar
ARFLAGS = rv
################################
%.o: %.c %.h
$(CO) $(CFLAGS) -c $<
%.o: %.c
$(CO) $(CFLAGS) -c $<
################################
.PHONY: all
all: $(EXEC1) 
$(EXEC1): $(OBJS1) $(LIBS1) 
$(LD) -o $@ $(LFLAGS) $^
.PHONY: run1
run1: $(EXEC1)
./$(EXEC1)
#################################
#Sprzataczka i archiwizacja#
.PHONY: clean tar
clean:                                                     
rm -f .o  *~ *.a *.so *.x core core a.out; rm -rf ${LIB_DIR}
#################################
tar: clean
(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
