SQLITE = -lsqlite3
CC = g++ -g
LIB = libfuncs.a
TARGET = main
HEADPATH = -I../include
OBJ = write.o erase.o show.o modify.o allclean.o find.o sorting.o
OBJ_C = write.c erase.c show.c modify.c allclean.c find.c sorting.c

$(TARGET): main.o $(LIB)
	$(CC) main.o $(HEADPATH) -L. -lfuncs $(SQLITE) -o $@

$(LIB): $(OBJ)
	ar rv $@ $(OBJ)

%.o:%.c
	$(CC) -c $< -o $@ $(HEADPATH) $(SQLITE)

clean:
	rm -rf *.o $(LIB) $(TARGET) *.db
