#include <stdio.h>


int main()
{
  
  
  char ** s;

  char ** s_zero = s;
  
  *s++ = "The";
  *s++ = "Swag";
  *s++ = "Monster";
  *s++ = "is";
  *s++ = "here";
  *s++ = NULL;

  while (*s_zero != NULL )
  {
    printf("%s\n",*s_zero++);
  }

}
