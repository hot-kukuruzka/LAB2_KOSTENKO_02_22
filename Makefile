TARGET = MyLab
.PHONY: clean run

$(TARGET) : main.o bin.o oct.o hex.o common_funcs.o
	gcc main.o bin.o oct.o hex.o common_funcs.o -o $(TARGET)

main.o : main.c
	gcc -c main.c

bin.o : bin.c
	gcc -c bin.c

oct.o : oct.c
	gcc -c oct.c

hex.o : hex.c
	gcc -c hex.c

common_funcs.o : common_funcs.c
	gcc -c common_funcs.c

clean : 
	rm $(TARGET) *.o

run : $(TARGET)
	./$(TARGET)
