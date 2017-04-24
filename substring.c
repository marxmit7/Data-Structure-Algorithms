#include<stdio.h>
#include<string.h>
int main()
{
  char s[200]="given is the string that i want";
        printf("%s\n",s );
        printf("enter the substring to be checked\n");
  char t[50];
  gets(t);
  char *p;
  p=strstr(s,t);
  if(p!=NULL)
  {printf("successfull\n");}
  else
  printf("unsuccessful\n");


  return 0;


}
