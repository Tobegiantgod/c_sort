#include<stdio.h>

void bubble_sort(int *a, int length)
{
    int i,j,t;
    for(j=length-1;j>=1;j--)
    {
        for(i=0;i<j;i++)
        {
            if(a[i]>a[i+1])
            {
                t=a[i];
                a[i]=a[i+1];
                a[i+1]=t;
            }
        }
    }
}

int main()
{
    int m,i;
    scanf("%d",&m);
    int buf[m];
    for(i=0;i<m;i++)
        scanf("%d",&buf[i]);
    bubble_sort(buf, m);
    for(i=0;i<m;i++)
        printf("<%d",buf[i]);
    return 0;
}


             
