#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
    int value;
    struct _node *next;
} Node;

int main()
{

    int array[10];
    Node *pam1 = (Node *)malloc(sizeof(Node));
    Node *pam2 = (Node *)malloc(sizeof(Node));
    Node pa1;
    Node pa2;

    printf("0x%08X,0x%08X\n",&pa1, &pa2);
    printf("0x%08X,0x%08X\n",pam1,pam2);
    printf("0x%08X,0x%08X\n",&pam1, &pam2);
    return 0;
}