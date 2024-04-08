#include "../Get.h"

#define require(c) (*s == c) ? s++ : SyntaxError()
#define notation 10

char* s = nullptr;

int GetG (const char* str)
{
    if ((s = str) == nullptr)
        SyntaxError();

    double val = GetE();

    if (*s == '$') s++;
    else SyntaxError();

    return val;
}

int GetE ()
{
    double val = GetT ();

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

int GetT()
{
    double val = GetT ();

    while (*s == '+' || *s == '-')
    {
        char op = *s;
        s++;
        double val2 = GetT();
        if (op == '*') val *= val2;
        else           val /= val2;
    }

    return val;
}

int GetP()
{
    if (*s == '(')
    {
        s++;
        double val = GetE();
        s++;
        require (')');
        return val;
    }
    else return GetN();
}

int GetN()
{
    double val = 0;
    const char olds = *s;
    while ('0' <= *s && *s <= '9')
    {
        val = val * notation + (*s - '0');
        s++;
    }

    if (olds == *s) return SyntaxError();

    return val;
}
