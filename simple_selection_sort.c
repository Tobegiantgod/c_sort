#include<stdio.h>

void selection_sort(int a[], int num)
{
    int i,j,t;
    for(i=0;i<num-1;i++)
    {
        int t=i; //记录最小的数的下标
        for(j=i+1;j<num;j++)
        {
            if(a[j]<a[t])
                t=j;
        }
        if (t!=i)
        {
            int tmp=a[i];
            a[i]=a[t];
            a[t]=tmp;
        }
    }
}

int main()
{
    int nums;
    scanf("%d",&nums);
    int buf[nums];
    for(int i=0;i<nums;i++)
        scanf("%d",&buf[i]);
    selection_sort(buf, nums);
    for(int j=0;j<nums;j++)
        printf("<%d",buf[j]);
    return 0;
}













