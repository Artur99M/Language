CC = g++

ALLOBJFILES = obj/main.o obj/read.o obj/Get.o TREE_EXP/obj/readfile.o TREE_EXP/obj/tree.o TREE_EXP/obj/Diff.o TREE_EXP/obj/SimpleTreeExp.o
ALLCPPFILES = src/main.cpp src/read.cpp src/Get.cpp TREE_EXP/obj/readfile.o TREE_EXP/obj/tree.o TREE_EXP/obj/Diff.o TREE_EXP/obj/SimpleTreeExp.o Onegin/readtext.cpp

deb:
	$(CC) -DDEBUG $(ALLCPPFILES)


all: $(ALLOBGFILES)

obj/main.o: src/main.cpp
	$(CC) -c src/main.cpp -o obj/main.o

obj/Get.o: src/Get.cpp
	$(CC) -c src/Get.cpp -o obj/Get.o

obj/read.o: src/read.cpp
	$(CC) -c src/read.cpp -o obj/read.o

run:
	$(CC) $(ALLOBJFILES) -o Language.out

app:
	./Language.out

clean :
	rm *.out obj/*.o
