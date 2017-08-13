#include <stdio.h>

void quick_sort(int array[], int low, int hight)
{
    int i,j,t,m;
    if(low<hight)
    {
        i=low;
        j=hight;
        t=array[low];//第一个数为轴
        while(i<j)
        {
            while(i<j && array[j]>t)
                j--;
            if(i<j)
            {
                m=array[i];
                array[i]=array[j];
                array[j]=m;
                i++;
            }
            while(i<j && array[i]<=t)
                i++;
            if(i<j)
            {
                m=array[j];
                array[j]=array[i];
                array[i]=m;
                j--;
            }
        }
        array[i]=t;
        quick_sort(array,0,i-1);
        quick_sort(array,i+1,hight);
    }
}

void px_quick_sort(int buf[], int size)
{
    quick_sort(buf,0,size-1);
}

int main()
{
    int m,i;
    printf("please input how many numbers:");
    scanf("%d",&m);
    int buf[m];
    for(i=0;i<m;i++)
        scanf("%d",&buf[i]);
    px_quick_sort(buf,m);
    for(i=0;i<m;i++)
        printf("<%d",buf[i]);
    printf("\n");
    return 0;
}







                

