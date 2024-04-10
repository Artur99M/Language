#include "../include/Get.h"
#include "../DEBUG/def.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define require(c) (**s == c) ? *s++ : SyntaxError();
#define notation 10

void SkipSpace (char** s);
double Syntax_Error (char** s, const char func[5]);
bool ismathfunc (char** s, char* mathfunc, const char func[5]);
#define isfunc(s, mathfunc) ismathfunc (s, mathfunc, __func__)

#define SyntaxError() Syntax_Error(s, __func__)

double GetG (char* str)
{
    PRINT_DEBUG ("\n");
    char* s = str;

    PRINT_DEBUG ("s = \"%s\"\n", s);
    SkipSpace(&s);
    double val = GetE(&s);
    SkipSpace(&s);
    PRINT_DEBUG ("*s = %c\n", *s);

    if (*s == '$') s++;
    else return Syntax_Error(&s, __func__);
    return val;
}

double GetE (char** s)
{
    PRINT_DEBUG ("\n");
    SkipSpace(s);
    double val = GetT (s);
    SkipSpace(s);
    PRINT_DEBUG ("**s = %c\n", **s);

    while (**s == '+' || **s == '-')
    {
        char op = **s;
        (*s)++;
        SkipSpace(s);
        double val2 = GetT(s);
        SkipSpace(s);
        if (op == '+') val += val2;
        else           val -= val2;
    }

    return val;
}

double GetT(char** s)
{
    PRINT_DEBUG ("\n");
    SkipSpace(s);
    double val = GetL (s);
    SkipSpace(s);
    PRINT_DEBUG ("**s = %c\n", **s);

    while (**s == '*' || **s == '/')
    {
        char op = **s;
        (*s)++;
        SkipSpace(s);
        double val2 = GetL(s);
        SkipSpace(s);
        if (op == '*') val *= val2;
        else           val /= val2;
    }

    return val;
}

double GetP(char** s)
{
    PRINT_DEBUG ("\n");
    SkipSpace(s);
    PRINT_DEBUG ("**s = %c\n", **s);
    double val = 0;
    int sign = 1;
    if (**s == '-')
    {
        (*s)++;
        sign = -1;
    }
    SkipSpace(s);
    if (**s == '(')
    {
        (*s)++;
        val = GetE(s);
        SkipSpace(s);
        PRINT_DEBUG ("**s = %c\n", **s);
        if (**s == ')') (*s)++;
        else return SyntaxError();
    }
    else
    {
        val = GetN(s);
        SkipSpace(s);
        PRINT_DEBUG ("val = %lf\n", val);
    }

    return val * sign;
}

double GetN(char** s)
{
    PRINT_DEBUG ("\n");
    double val = 0;
    SkipSpace(s);
    const char* olds = *s;
    int sign = 1;
    if (**s == '-')
    {
        (*s)++;
        sign = -1;
    }
    while ('0' <= **s && **s <= '9')
    {
        PRINT_DEBUG ("**s = %c\n", **s);
        val = val * notation + (**s - '0');
        (*s)++;
    }
    PRINT_DEBUG ("val = %lf\n", val);
    if (olds == *s)
        return SyntaxError();
    if (**s == '.' || **s == ',')
    {
        PRINT_DEBUG ("**s = %c\n", **s);
        (*s)++;
        olds = *s;
        int exp10 = 10;
        while ('0' <= **s && **s <= '9')
        {
            PRINT_DEBUG ("**s = %c\n", **s);
            double x = 0;
            x += (**s - '0');
            x /= exp10;
            val += x;
            PRINT_DEBUG ("val = %lf\n", val);
            exp10 *= 10;
            (*s)++;
        }
        if (olds == *s) return SyntaxError();

    }
    PRINT_DEBUG ("val = %lf\n", val);


    return val * sign;
}

void SkipSpace (char** s)
{
    while (**s == ' ' || **s == '\t')
        (*s)++;
}

double Syntax_Error (char** s, const char func[5])
{
    fprintf(stderr, "ERROR: \'%c\' in text in func \'%s\'\n", **s, func);
    return 0;
}

double GetL (char** s)
{
    PRINT_DEBUG ("start\n");
    SkipSpace(s);
    double val = GetP (s);
    SkipSpace(s);
    PRINT_DEBUG ("**s = %c\n", **s);

    if (**s == '^')
    {
        char op = **s;
        (*s)++;
        SkipSpace(s);
        double val2 = GetP(s);
        SkipSpace(s);
        val = pow (val, val2);
    }

    if (isfunc (s, "log"))
    {
        SkipSpace(s);
        double val2 = GetN (s);
        if (val == 1 || val <= 0 || val2 <= 0)
            return SyntaxError();
        val = log (val2) / log (val);
    }

    return val;
}

bool ismathfunc (char** s, char* mathfunc, const char func[5])
{
    PRINT_DEBUG ("mathfunc = %s\n", mathfunc);
    for (int i = 0; i < strlen (mathfunc); i++)
    {
        PRINT_DEBUG ("**s = %c\n", **s);
        if (**s == mathfunc[i])
            (*s)++;
        else return Syntax_Error (s, func);
    }

    return true;
}
