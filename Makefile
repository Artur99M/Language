CC = g++

FILESFORCOMP = obj/main.o obj/Get.o obj/read.o TREE_EXP/obj/Diff.o
ALLOBJFILES = obj/main.o obj/read.o obj/Get.o TREE_EXP/obj/readfile.o TREE_EXP/obj/tree.o TREE_EXP/src/Diff.o TREE_EXP/obj/SimpleTreeExp.o Onegin/readtext.o Onegin/txtDtor.o obj/TeX.o
ALLCPPFILES = src/main.cpp src/read.cpp src/Get.cpp TREE_EXP/obj/readfile.o TREE_EXP/obj/tree.o TREE_EXP/src/Diff.cpp TREE_EXP/obj/SimpleTreeExp.o Onegin/readtext.o Onegin/txtdtor.o src/TeX.cpp

all : $(FILESFORCOMP)

obj/main.o: src/main.cpp include/Get.h include/read.h DEBUG/def.h
	$(CC) -c src/main.cpp -o obj/main.o

obj/Get.o: src/Get.cpp DEBUG/def.h include/Get.h TREE_EXP/Tree1/header/tree.h TREE_EXP/header/TREE_EXP.h
	$(CC) -c src/Get.cpp -o obj/Get.o

obj/read.o: src/read.cpp Onegin/header/readtext.h include/read.h
	$(CC) -c src/read.cpp -o obj/read.o

obj/TeX.o: src/TeX.cpp include/TeX.h TREE_EXP/Tree1/header/tree.h TREE_EXP/header/TREE_EXP.h
	$(CC) -c src/TeX.cpp -o obj/TeX.o

TREE_EXP/obj/Diff.o : DEBUG/def.h TREE_EXP/src/Diff.cpp TREE_EXP/header/Diff.h TREE_EXP/Tree1/src/tree.cpp TREE_EXP/Tree1/header/tree.h TREE_EXP/header/TREE_EXP.h
	$(CC) -c TREE_EXP/src/Diff.cpp -o TREE_EXP/obj/Diff.o

run:
	$(CC) $(ALLOBJFILES) -o Language.out

app:
	./Language.out

deb:
	$(CC) -DDEBUG $(ALLCPPFILES)

clean :
	rm *.out obj/*.o TeX/main.idx TeX/main.ilg TeX/main.ind TeX/main.log TeX/main.out TeX/main.synctex.gz TeX/matlab.aux TeX/main.aux TeX/main.fls TeX/main.fdb TeX/main.fdb_latexmk
