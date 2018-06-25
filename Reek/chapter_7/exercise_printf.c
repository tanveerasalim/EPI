#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <float.h>

#define MAX_LENGTH 1000

void reverse (char *s)
{
	char temp;	
	
	for ( int i = 0, j = strlen(s)-1; i < j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

char * ltoa(long long int n)
{
  	static char s[MAX_LENGTH];

	long long int i, sign;

	if ((sign = n) < 0) /* record sign */
		n = -n;	    /* make n positive by n =-n */
	i = 0;
	do 		/* generate digits in reverse order */
	{
		s[i++] = lldiv(n,10).rem + '0'; /* get next digit with n % 10 + '0'; */

	} while (n = lldiv(n,10).quot, n > 0);       /* delete it with while ( (n /= 10) > 0 )*/
	
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);

	return s;
}

char * ftoa(const double input)
{
  double in = input; long long int f_to_i;

  static char a[MAX_LENGTH];

  f_to_i = (long long int)in; 
  
  strcat(a,ltoa(f_to_i)); strcat(a,".");

  double * integral;

  const double fraction = modf(input,integral); /* stores fractional part of input */
  
  static int i; double divisor = 0.1;

  while ( i < 6 ) 	/* by default %f in printf is six decimal digits precise  */
  {
	strcat(a,ltoa(((long long int)(fraction/divisor))%10));

	divisor /= 10; i++;
  }

  return a;
}


int myprintf(char const * s)
{
  while (*s != '\0')
    putchar(*s++);
  return 1;
}

int main(void) 
{

	printf("%s\n",ltoa(-23));
	printf("%s\n",ltoa(LLONG_MAX));
	printf("%s\n",ltoa(12345678901234));
	printf("%s\n",ltoa(-1));
	printf("%s\n",ltoa(LLONG_MIN)); //FAILS: prints "-("
	printf("%s\n",ltoa(-LLONG_MAX));
	printf("%s\n",ltoa(-123456789));
	printf("%s\n",ltoa(INT_MIN));
	printf("%s\n",ltoa(LONG_MIN)); //FAILS
	printf("%s\n",ltoa(-LONG_MAX));
	printf("%s\n",ltoa(LONG_MAX));
	printf("%s\n",ltoa(-33238280));


}

