#include <stdio.h>
#include "../include/Get.h"
#include "../include/read.h"
#include "../DEBUG/def.h"
#include "../Onegin/header/txtdtor.h"
#include "../TREE_EXP/Tree1/header/tree.h"

int main()
{

    PRINT_DEBUG ("bark\n");
    text txt = read ("data/file.txt");
    PRINT_DEBUG ("txt.nimlines = %lu\n", txt.numlines);
    for (size_t i = 0; i < txt.numlines - 1; i++)
    {
        Node* x = GetG(txt.line[i].str);
        TreePrint (x);
    }
    txtDtor (&txt);


}
