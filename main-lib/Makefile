SQLITE = -lsqlite3
CC = g++ -g
LIB = libfuncs.a
TARGET = main
HEADPATH = -I/home/do/termproject/include
LIBPATH = -L/home/do/termproject/lib
OBJ = write.o erase.o
OBJ_C = write.c erase.c

$(TARGET): main.o $(LIB)
	$(CC) main.o $(HEADPATH) -L. -lfuncs $(SQLITE) -o $@

main.o: main.c
	$(CC) -c $< -o $@ $(HEADPATH) $(SQLITE)

$(LIB): $(OBJ)
	ar rv $@ $(OBJ)

%.o:%.c
	$(CC) -c $< -o $@ $(HEADPATH) $(SQLITE)

clean:
	rm -rf *.o $(LIB) $(TARGET) *.db
