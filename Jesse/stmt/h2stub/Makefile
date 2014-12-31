#.SUFFIXES: .y .l .c .o
.SUFFIXES: .c .o

CC=xlC_r
CFLAGS= -c

OBJ1 =  StmtParser.o StmtLex.o

all: h2stub

h2stub: $(OBJ1)
	$(CC) -o $(HOME)/bin/$@ $(OBJ1)

.c.o:
	$(CC) $(CFLAGS) $(INCLDIR) $<

clean:
#	rm -f *.o *.c *.h *.output
	rm -f *.o *.output
