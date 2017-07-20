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
		int sum1 = 0; 
    int l = 0;

    if (*x >= '0' && *x <= '9') {
	    while (*x >= '0' && *x <= '9')
	    {
					sum1= (sum1* 10) + (*x - '0');
					*x++;
					l++;
    	} 
			return sum1;
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
