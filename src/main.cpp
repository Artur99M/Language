#include <stdio.h>
#include "../include/Get.h"
#include "../include/read.h"
#include "../DEBUG/def.h"

int main()
{

    PRINT_DEBUG ("bark\n");
    text txt = read ("data/file.txt");
    double x = GetG(txt.alltext);
    printf ("%0.0lf\n", x);

}
