#include "../include/TeX.h"
#include "../TREE_EXP/header/TREE_EXP.h"
#include "../DEBUG/def.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const size_t start_size = 100;
FILE* outfile = fopen ("TeX/TeX.tex", "w");

void TEX_PRINT (const Node* pNode)
{
    PRINT_DEBUG ("start\n");
    char* str = node_to_str (pNode);
    PRINT_DEBUG ("I print \"%s\"\n", str);
    fprintf (outfile, "\\[%s\\]\n", str);
    free (str);
}

char* node_to_str (const Node* pNode)
{
    PRINT_DEBUG ("start\n");
    if (pNode == nullptr)
        return nullptr;

    char* str = nullptr;
    switch (pNode->type)
    {
        case VARIABLE:
            PRINT_DEBUG ("I\'m in VARIABLE\n");
            str = (char*) calloc (10, sizeof (char));
            PRINT_DEBUG ("I find memory\n");
            str[0] = pNode->value.variable;
            break;
        case NUMBER:
            PRINT_DEBUG ("I\'m in NUMBER\n");
            str = (char*) calloc (20, sizeof (char));
            sprintf (str, "%lf", pNode->value.number);
            str[20] = '\0';
            break;
        case OPERATION:
            PRINT_DEBUG ("I\'m in OPERATION\n");
            char *l = nullptr, *r = nullptr;
            if (pNode->left != nullptr)
                l = node_to_str (pNode->left);
            if (pNode->right != nullptr)
                r = node_to_str (pNode->right);
            PRINT_DEBUG ("l = %s, r = %s\n", l, r);
            size_t size = 0;
            size_t size_l = 0;
            switch (pNode->value.operation)
            {
                case ADD:
                    PRINT_DEBUG ("I\'m seeing operation ADD\n");
                    size_l = strlen (l);
                    size = size_l + strlen (r) + 2;
                    str = (char*) calloc (size, sizeof (char));
                    strcpy (str, l);
                    PRINT_DEBUG ("1: str = %s\n", str);
                    str[size_l] = '+';
                    PRINT_DEBUG ("2: str = %s\n", str);
                    strncat (str, r, size - 1);
                    free (r);
                    PRINT_DEBUG ("3: str = %s\n", str);
                    free (l);
                    PRINT_DEBUG ("4: str = %s\n", str);
                    break;
                case SUB:
                    PRINT_DEBUG ("I\'m seeing operation SUB\n");
                    if (l == nullptr)
                    {
                        str = (char*) calloc (strlen (r) + 2, sizeof (char));
                        str[1] = '-';
                        strcat (str, r);
                        free (r);
                    }
                    else
                    {
                        size_l = strlen (l);
                        size = size_l + strlen (r) + 2;
                        str = (char*) calloc (strlen (l) + strlen (r) + 2, sizeof (char));
                        strcpy (str, l);
                        free (l);
                        str[size_l] = '-';
                        strncat (str, r, size - 1);
                        free (r);
                    }
                case MUL:
                    PRINT_DEBUG ("I\'m seeing operation MUL\n");
                    size_l = strlen (l);
                    size = size_l + strlen (r) + 6;
                    str = (char*) calloc (size, sizeof (char));
                    strcpy (str, l);
                    // free (l);
                    strncat (str, "\\cdot ", size - 1);
                    strncat (str, r, size - 1);
                    // free (r);
                    break;
                case EXP:
                    PRINT_DEBUG ("I\'m seeing operation EXP\n");
                    size_l = strlen (l);
                    size = size_l + strlen (r) + 4;
                    str = (char*) calloc (size, sizeof (char));
                    strcpy (str, l);
                    free (l);
                    strncat (str, "^{", size - 1);
                    strncat (str, r, size - 1);
                    free (r);
                    strncat (str, "}", size - 1);
                    break;
                case DIV:
                    PRINT_DEBUG ("I\'m seeing operation DIV\n");
                    size_l = strlen (l);
                    size = size_l + strlen (r) + 10;
                    str = (char*) calloc (size, sizeof (char));
                    strcpy (str, "\\frac{");
                    strncat (str, l, size - 1);
                    free (l);
                    strncat (str, "}{", size - 1);
                    strncat (str, r, size - 1);
                    free (r);
                    strncat (str, "}", size - 1);
                    break;
                case LOG:
                    PRINT_DEBUG ("I\'m seeing operation LOG\n");
                    size_l = strlen (l);
                    size = size_l + strlen (r) + 19;
                    str = (char*) calloc (size, sizeof (char));
                    strcpy (str, "\\log_{");
                    strncat (str, l, size - 1);
                    free (l);
                    strncat (str, "}\\left(", size - 1);
                    strncat (str, r, size - 1);
                    free (r);
                    strncat (str, "\\right)", size - 1);
                    break;
                case SIN:
                    PRINT_DEBUG ("I\'m seeing operation SIN\n");
                    size = strlen (l) + 18;
                    str = (char*) calloc (size, sizeof (char));
                    strcat (str, "\\sin\\left(");
                    strncat (str, l, size - 1);
                    free (l);
                    strncat (str, "\\right)", size - 1);
                    break;
                case COS:
                    PRINT_DEBUG ("I\'m seeing operation COS\n");
                    size = strlen (l) + 18;
                    str = (char*) calloc (size, sizeof (char));
                    strcpy (str, "\\cos\\left(");
                    strncat (str, l, size - 1);
                    free (l);
                    strncat (str, "\\right)", size - 1);
                    break;
                case TG:
                    PRINT_DEBUG ("I\'m seeing operation TG\n");
                    size = strlen (l) + 17;
                    str = (char*) calloc (size, sizeof (char));
                    strcpy (str, "\\tg\\left(");
                    strncat (str, l, size - 1);
                    free (l);
                    strncat (str, "\\right)", size - 1);
                    break;
                case CTG:
                    PRINT_DEBUG ("I\'m seeing operation CTG\n");
                    size = strlen (l) + 18;
                    str = (char*) calloc (size, sizeof (char));
                    strcpy (str, "\\ctg\\left(");
                    strncat (str, l, size - 1);
                    free (l);
                    strncat (str, "\\right)", size - 1);
                    break;
                case ARCSIN:
                    PRINT_DEBUG ("I\'m seeing operation ARCSIN\n");
                    size = strlen (l) + 21;
                    str = (char*) calloc (size, sizeof (char));
                    strcpy (str, "\\arcsin\\left(");
                    strncat (str, l, size - 1);
                    free (l);
                    strncat (str, "\\right)", size - 1);
                    break;
                case ARCCOS:
                    PRINT_DEBUG ("I\'m seeing operation ARCCOS\n");
                    size = strlen (l) + 21;
                    str = (char*) calloc (size, sizeof (char));
                    strcpy (str, "\\arccos\\left(");
                    strncat (str, l, size - 1);
                    free (l);
                    strncat (str, "\\right)", size - 1);
                    break;
                case ARCTG:
                    PRINT_DEBUG ("I\'m seeing operation ARTCG\n");
                    size = strlen (l) + 20;
                    str = (char*) calloc (size, sizeof (char));
                    strcpy (str, "\\arctg\\left(");
                    strncat (str, l, size - 1);
                    free (l);
                    strncat (str, "\\right)", size - 1);
                    break;
                case ARCCTG:
                    PRINT_DEBUG ("I\'m seeing operation ARCCTG\n");
                    size = strlen (l) + 21;
                    str = (char*) calloc (size, sizeof (char));
                    strcpy (str, "\\arcctg\\left(");
                    strncat (str, l, size - 1);
                    free (l);
                    strncat (str, "\\right)", size - 1);
                    break;
                case EQUAL:
                    PRINT_DEBUG ("I\'m seeing operation EQUAL\n");
                    size = strlen (r) + strlen (l) + 4;
                    str = (char*) calloc (size, sizeof (char));
                    strcpy (str, r);
                    strncat (str, " = ", size - 1);
                    strncat (str, l, size - 1);
                    free (l);
                    break;

            }
    }
    PRINT_DEBUG ("str = %s\n", str)
    return str;
}
