#include <stdio.h>
#include <stdbool.h>

int parseSum();
int parseProduct();
int parseFactor();

char *x;

bool errorFlag = false;


int parseSum()
{
    int pro1 = parseProduct();
    while (*x == '+')
    {
        int pro2;
        ++x;
        pro2 = parseProduct();
        pro1 = pro1 + pro2;
    }
    return pro1;
}

int parseProduct()
{
    int fac1 = parseFactor();
    while (*x == '*')
    {
        int fac2;
        ++x;
        fac2 = parseFactor();
        fac1 = fac1 * fac2;
    }
    return fac1;
}

int parseFactor()
{
    if (*x >= '0' && *x <= '9')
    {
        return *x++ - '0';
    } else if (*x == '(') {
        int sum;
        ++x; /* consume ( */
        sum = parseSum();
        ++x; /* consume ) */
        return sum;
    } else {
        printf("expected digit but found '%c'\n", *x);
        errorFlag = true;
        return 0;
    }

}

int main()
{
		char buffer[80];
    int r = 0;
//    x = "2*3+4*5";
		gets(buffer);
		x = (char *) &buffer;
    r = parseSum();
    printf ("%u\n", r);
    return 0;

}
