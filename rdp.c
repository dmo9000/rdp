#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>


typedef int64_t mathRegister;
mathRegister parseSum();
mathRegister parseProduct();
mathRegister parseFactor();

char *x;

bool errorFlag = false;

mathRegister parseSum()
{
    mathRegister pro1 = parseProduct();
    while (*x == '+')
    {
        mathRegister pro2;
        ++x;
        pro2 = parseProduct();
        pro1 = pro1 + pro2;
    }
    return pro1;
}

mathRegister parseProduct()
{
    mathRegister fac1 = parseFactor();
    while (*x == '*')
    {
        mathRegister fac2;
        ++x;
        fac2 = parseFactor();
        fac1 = fac1 * fac2;
    }
    return fac1;
}

mathRegister parseFactor()
{
		mathRegister sum1 = 0; 
    if (*x >= '0' && *x <= '9') {
	    while (*x >= '0' && *x <= '9')
	    {
					sum1= (sum1* 10) + (*x - '0');
					*x++;
    	} 
			return sum1;
		} else if (*x == '(') {
        mathRegister sum;
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
    mathRegister r = 0;
		gets(buffer);
		x = (char *) &buffer;
    r = parseSum();
    printf ("%llu\n", r);
    return 0;

}
