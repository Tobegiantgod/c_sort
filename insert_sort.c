#include<stdio.h>

void insert_sort(int a[], int n)
{
    for (int i=1;i<n;i++){
        int tmp = a[i];
        int j = i-1;
        while(j>0&&tmp<a[j]){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=tmp;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int buf[n];
    for(int i=0;i<n;i++)
        scanf("%d",&buf[i]);
    insert_sort(buf, n);
    for(int j=0;j<n;j++)
        printf("<%d",buf[j]);
    return 0;
}

