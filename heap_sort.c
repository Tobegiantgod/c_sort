#include<stdio.h>

void adjust_heap(int a[],int s, int n)
{
    int rc=a[s];
    for(int i=s*2;i<=n;i*=2)
    {
        if(i<n && a[i]>a[i+1])
            i++;
        if(rc<=a[i])
            break;
        a[s]=a[i];
        s=i;
    }
    a[s]=rc;
}

void creat_heap(int a[], int n)
{
    for(int i=n/2;i>0;i--)
        adjust_heap(a, i, n);
}

void head_sort(int a[], int n)
{
    creat_heap(a, n);
    for(int i=n;i>1;i--)
    {
       int x=a[1];
       a[1]=a[i];
       a[i]=x;
       adjust_heap(a,1,i-1);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int buf[n+1];
    for(int i=1;i<=n;i++)
        scanf("%d",&buf[i]);
    head_sort(buf,n);
    for(int j=1;j<=n;j++)
        printf("%d",buf[j]);
}
















