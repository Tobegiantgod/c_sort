#include<stdio.h>

int get_looptimes(int a[], int n)
{
    int max=a[0];
    for(int i=1;i<n;i++)
    {
	if(max<a[i])
            max=a[i];
    }
    int count=1;
    int j=1;
    int tmp=max;
    //printf("%d",count);
    while (1)
    {
        tmp = tmp/10;
        count++;
        if(tmp<10)
        {
            break;
        }
    }
    return count;
}


void ex_radix_sort(int *p, int n, int loop)
{
    int buckets[10][20]={0};
    int d=1;
    int count=1;
    while(count<loop)
    {
        d*=10;
        count++;
    }
    int i,j;
    for(i = 0; i < n; i++)
    {
        int row_index = (*(p + i) / d) % 10;
        for(j = 0; j < 20; j++)
        {
            if(buckets[row_index][j] == 0)
            {
                buckets[row_index][j] = *(p + i);
                break;
            }
        }
    }
    //将桶中的数，倒回到原有数组中
    int k = 0;
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 20; j++)
        {
            if(buckets[i][j] != 0)
            {
                *(p + k) = buckets[i][j];
                buckets[i][j] = 0;
                k++;
            }
        }
    }
    for(i=0;i<n;i++)
        printf("%d ",*(p+i));
    printf("\n");
}


void radix_sort(int a[], int n)
{
    int loops=0;
    loops = get_looptimes(a, n);
    int i;
    for(i=1;i<=loops;i++)
    	ex_radix_sort(a, n, i);
}


int main()
{
    int n;
    scanf("%d",&n);
    int buf[n];
    for(int i=0;i<n;i++)
        scanf("%d",&buf[i]);
    radix_sort(buf, n);
    for(int j=0;j<n;j++)
    	printf("%d ",buf[j]);
    return 0;
}



