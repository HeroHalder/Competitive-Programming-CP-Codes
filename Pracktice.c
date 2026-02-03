#include<stdio.h>
#define size 5
int stack[size];
int top=-1;

void push(int value)
{
    if(top==size-1)
        printf("Stack is full\n");
    else
    {
        top++;
        stack[top]=value;
        printf("Pushed= %d\n",value);
    }

}
void pop()
{
    if(top==-1)
        printf("Stack is empty..\n");
    else
        printf("Poped= %d\n",stack[top]);
    top--;
}
void display()
{
    if(top==-1)
        printf("Stack is Empty..\n");
    else
    {
        printf("Stack Elements:\n");


        for(int i=top; i>=0; i--)
            printf("%d\n",stack[i]);


    }
}
int main()
{

    push(10);
    push(20);
    push(30);

    display();
    pop();
    display();
    return 0;
}
