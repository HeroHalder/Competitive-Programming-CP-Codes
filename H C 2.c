#include<stdio.h>
int main (){
int i;
int a[10];

printf("Enter the size of the array: ");
scanf("%d",&n);
int arr[n];
printf("Enter the value of array: ");

 for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
    if(arr[i]==3)
      {
        pos=i;
        printf("possition: %d",pos); // There is a plm..
        break;
      }
    else
    printf("This value is not found");
 }
}
