#include<stdio.h>
#include<stdbool.h>
int main(){
long int lint;
long long int llint;
long double ldouble;
short int sint;
lint= 10280384;
llint= 12345458998832028;
ldouble= 1.1E+493;
sint= 1234;

printf("Long int: %ld\n",lint);
printf("Long Long int: %lld\n",llint);
printf("Long double: %le\n",ldouble);
printf("sort int: %hd",sint);
getch();
return 0;

}
