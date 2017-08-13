#include<stdio.h>
#include<stdlib.h>

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
    int tmp;
    while (1)
    {
        tmp = max/10;
        count++;
        if(tmp<10)
            break;
    }
    return count;
}


void ex_radix_sort(int a[], int n, int loops)
{
    int tmp_bucket[10][20]={-1};
    //除子
    int tmp=1;
    int count=1;
    int index;
    while(count<=loops)
    {
	for(int i=0;i<n;i++)
        {
            index = (a[i]/tmp)%10;
            for(int j=0;j<n;j++)
            {
		if(tmp_bucket[index][j]==-1)
                {
                    tmp_bucket[index][j]=a[i];
                    break;
                }
            }
        }
        int i,j,k=0;
        while (j<10)
        {
           while(k<n)
           {   
               if(tmp_bucket[j][k]!=-1)
               {  
                   a[i++]=tmp_bucket[j][k];
                   tmp_bucket[j][k]=-1;
                   k++;
               }                
               else
               {
                   j+=1;
                   k=0;
                   break;
               }
           }
        }
        count++; 
     }
}

void radix_sort(int *a, int n)
{
    int loops=0;
    loops = get_looptimes(a, n);
    ex_radix_sort(a, n, loops);
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



