#include "../include/Get.h"
#include <stdio.h>
#include "../DEBUG/def.h"

#define SyntaxError();                                                       \
    {                                                                        \
    fprintf(stderr, "ERROR: \'%c\' in text in func \'%s\'\n", *s, __func__); \
    return 0;                                                                \
    }

#define require(c) (*s == c) ? s++ : SyntaxError();
#define notation 10

char* s = nullptr;

double GetG (char* str)
{
    PRINT_DEBUG ("\n");
    s = str;

    PRINT_DEBUG ("s = \"%s\"\n", s);
    double val = GetE();
    PRINT_DEBUG ("*s = %c\n", *s);

    if (*s == '$') s++;
    // else SyntaxError();
    return val;
}

double GetE ()
{
    PRINT_DEBUG ("\n");
    double val = GetT ();
    PRINT_DEBUG ("*s = %c\n", *s);

    while (*s == '+' || *s == '-')
    {
        char op = *s;
        s++;
        double val2 = GetT();
        if (op == '+') val += val2;
        else           val -= val2;
    }

    return val;
}

double GetT()
{
    PRINT_DEBUG ("\n");
    double val = GetP ();
    PRINT_DEBUG ("*s = %c\n", *s);

    while (*s == '*' || *s == '/')
    {
        char op = *s;
        s++;
        double val2 = GetT();
        if (op == '*') val *= val2;
        else           val /= val2;
    }

    return val;
}

double GetP()
{
    PRINT_DEBUG ("\n");
    PRINT_DEBUG ("*s = %c\n", *s);
    if (*s == '(')
    {
        s++;
        double val = GetE();
        s++;
        PRINT_DEBUG ("*s = %c\n", *s);
        if (*s == ')') s++;
        else SyntaxError();
        return val;
    }
    else
    {
        double val = GetN();
        PRINT_DEBUG ("val = %lf\n", val);
        return val;
    }
}

double GetN()
{
    PRINT_DEBUG ("\n");
    double val = 0;
    const char* olds = s;
    while ('0' <= *s && *s <= '9')
    {
        PRINT_DEBUG ("*s = %c\n", *s);
        val = val * notation + (*s - '0');
        s++;
    }
    PRINT_DEBUG ("val = %lf\n", val);
    if (olds == s) {
        SyntaxError();
        PRINT_DEBUG ("bark\n");
    }
    olds = s;
    if (*s == '.' || *s == ',')
    {
        PRINT_DEBUG ("*s = %c\n", *s);
        s++;
        unsigned int exp10 = 10;
        while ('0' <= *s && *s <= '9')
        {
            PRINT_DEBUG ("*s = %c\n", *s);
            val += (*s - '0') / exp10;
            s++;
            exp10 /= 10;
        }
        if (olds == s) SyntaxError();

    }
    PRINT_DEBUG ("val = %lf\n", val);


    return val;
}
