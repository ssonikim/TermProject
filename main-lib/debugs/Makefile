SQLITE = -lsqlite3
CC = g++ -g
LIB = libfuncs.a
TARGET = main_test
HEADPATH = -I/home/do/termproject/include
LIBPATH = -L/home/do/termproject/lib
OBJ = write.o erase.o
OBJ_C = write.c erase.c

$(TARGET): main_test.o $(LIB)
	$(CC) main_test.o $(HEADPATH) -L. -lfuncs $(SQLITE) -o $@

main_test.o: main_test.c
	$(CC) -c $< -o $@ $(HEADPATH) $(SQLITE)

$(LIB): $(OBJ)
	ar rv $@ $(OBJ)

$(OBJ): $(OBJ_C)
	$(CC) -c $< -o $@ $(HEADPATH) $(SQLITE)

clean:
	rm -rf *.o $(LIB) $(TARGET) *.db
