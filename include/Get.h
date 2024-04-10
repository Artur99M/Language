#ifndef GET_H
#define GET_H
#include <math.h>

double GetG(char*);
double GetN(char**);
double GetE(char**);
double GetT(char**);
double GetP(char**);
double GetL(char**);
double GetM(char**);


struct MATH_FUNC
{
    char name[10];
    double (*func)(double);
};

const struct MATH_FUNC math_funcs[] =
{
    // { "ln",     log }, проблема проверки значений
    { "sin",    sin },
    { "cos",    cos },
    { "tg",     tan },
    // { "ctg", ctan }, нет такой функции
    // { "arcsin", asin }, проблема проверки значений
    { "arctg",  atan }
};
const int nfuncs = sizeof (math_funcs);
#endif
