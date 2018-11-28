SQLITE = -lsqlite3
CC = gcc -g
LIB = libfuncs.a
TARGET = main_test
HEADPATH = -I/home/do/termproject/include
LIBPATH = -L/home/do/termproject/lib
OBJ = write.o

$(TARGET): main_test.o $(LIB)
	$(CC) main_test.o $(HEADPATH) $(LIBPATH) -lfuncs $(SQLITE) -o $@

$(LIB): $(OBJ)
	ar rv $@ $(OBJ)

%.o:%.c
	$(CC) -c $< -o $@ $(HEADPATH) $(SQLITE)
clean:
	rm -rf *.o $(LIB) $(TARGET) *.db
