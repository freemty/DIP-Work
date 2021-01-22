#include<stdio.h>
#include<string.h>
struct student
{
        char name[12];
        char birth[10];
        char number[20];
};
int main()
{
        struct student a[10],temp;
        int n;
        scanf("%d",&n);
        int i,j;
        int k;

        // printf("%d", a[0].name);
        // printf("%d", &a[0].name);
        for(i=0;i<n;i++){
                scanf("%s%s%s",a[i].name,a[i].birth,a[i].number);
        }
        for(i=0;i<n-1;i++){
                k=i;
                for(j=i+1;j<n;j++)
                        if(strcmp(a[k].birth,a[j].birth)==1) k=j;
                        temp=a[i];
                        a[i]=a[k];
                        a[k]=temp;
        }
        for(i=0;i<n;i++){
                printf("%s %s %s",a[i].name,a[i].birth,a[i].number);
                if(i!=n-1) printf("\n");
        }
        return 0;
}