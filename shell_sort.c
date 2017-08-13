#include<stdio.h>

void shell_sort(int a[], int n)
{
    int dk;
    int tmp;
    int i,j;
    for(dk=n/2;dk>0;dk/=2)
    {
        for(i=dk;i<n;i++)
        {
            tmp=a[i];
            for(j=i;j>=dk;j-=dk)
                if(tmp<a[j-dk])
                    a[j]=a[j-dk];
                else break;
            a[j]=tmp;
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int buf[n];
    for(int i=0;i<n;i++)
        scanf("%d",&buf[i]);
    shell_sort(buf, n);
    for(int j=0;j<n;j++)
        printf("%d ",buf[j]);
    return 0;
}


