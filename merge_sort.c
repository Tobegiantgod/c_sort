#include<stdio.h>
#include<stdlib.h>

void copy_array(int source[], int dest[], int start, int len)
{
    int i;
    int j=start;
    for(i=0;i<len;i++)
        dest[j++]=source[i];
}

//合并两个有序数列
void merge(int a[], int left, int right)
{
    int begin1 = left;
    int mid = (left+right)/2;
    int begin2 = mid+1;
    int k=0;
    int newArraylen = right - left + 1;
    int *b = (int *)malloc(newArraylen*sizeof(int));
    while (begin1<=mid && begin2<=right)
    {
        if(a[begin1]<=a[begin2])
            b[k++] = a[begin1++];
        else
            b[k++] = a[begin2++];
    }
    while (begin1<=mid)
        b[k++] = a[begin1++];
    while (begin2<=right)
        b[k++] = a[begin2++];
    copy_array(b, a, left, newArraylen);
    free(b);
}

//递归合并
void re_merge_sort(int a[], int left, int right)
{
    int i;
    if(left<right)
    {
        i = (left+right)/2;
        re_merge_sort(a, left, i);
        re_merge_sort(a, i+1, right);
        merge(a, left, right);
    }
}

//归并排序入口
void merge_sort(int a[], int n)
{
    re_merge_sort(a, 0, n-1);
}

int main()
{
    int n;
    scanf("%d", &n);
    int buf[n];
    for(int i=0;i<n;i++)
        scanf("%d", &buf[i]);
    merge_sort(buf, n);
    for(int j=0;j<n;j++)
        printf("%d ", buf[j]);
        
}






