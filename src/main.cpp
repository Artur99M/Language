#include <stdio.h>
#include "../include/Get.h"
#include "../include/read.h"
#include "../DEBUG/def.h"
#include "../Onegin/header/txtdtor.h"
#include "../TREE_EXP/Tree1/header/tree.h"
#include "../include/TeX.h"
#include "../TREE_EXP/header/Diff.h"
#include "../TREE_EXP/header/SimpleTreeExp.h"
#include "../include/graphviz.h"
#include <unistd.h>
#include <stdlib.h>

int main()
{

    PRINT_DEBUG ("bark\n");
    text txt = read ("data/file.txt");
    PRINT_DEBUG ("txt.nimlines = %lu\n", txt.numlines);
    Node* x = GetG(txt.line[0].str);
    SimplTree (x);
    TreePrint (x);
    Graphviz (x, "graphviz/Tree");
    txtDtor (&txt);
    // TEX_PRINT (x);
    // Graphviz (x, "graphviz/Tree.dot");
    Node* diff = Diff (x);
    // usleep (50000);
    // TreeFPrint (diff, "a.txt");
    // Graphviz (diff, "graphviz/Tree");
    Graphviz (diff, "graphviz/Tree2");
    puts ("\n\n\n\n\n\n\n");
    SimplTree (diff);
    Graphviz (diff, "graphviz/Tree3");
    // TreePrint (diff);
    // TEX_PRINT (diff);
    // SimplTree(x);


}
