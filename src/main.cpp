#include <stdio.h>
#include "../include/Get.h"
#include "../include/read.h"
#include "../DEBUG/def.h"
#include "../Onegin/header/txtdtor.h"
#include "../TREE_EXP/Tree1/header/tree.h"
#include "../include/TeX.h"
#include "../TREE_EXP/header/Diff.h"
#include "../TREE_EXP/header/SimpleTreeExp.h"

int main()
{

    PRINT_DEBUG ("bark\n");
    text txt = read ("data/file.txt");
    PRINT_DEBUG ("txt.nimlines = %lu\n", txt.numlines);
    Node* x = GetG(txt.line[0].str);
    TreePrint (x);
    Node* diff = Diff (x);
    TreePrint (diff);
    // SimplTree (diff);
    TEX_PRINT (diff, "TeX/TeX.tex");
    txtDtor (&txt);


}
