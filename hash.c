#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


#define MAX 1000

bool hashtable[MAX+1][2];
bool search(int x)
{
    if(x>=0)
    {
        if(hashtable[x][0]==1)
        return true;
        else 
        return false;
    }
    else{
        x=abs(x);
        if(hashtable[x][1]==1)
        {
        return true;
    }
        else
         return false;
    }
}

void insert(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]>=0)
        {
            hashtable[a[i]][0]==1;
        }
        else{
            hashtable[abs(a[i])][1]==1;
        }
    }
}


int main()
{
    int arr[]={12,45,78,-90,-89,-69};
    int n=sizeof(arr)/sizeof(arr[0]);

    insert(arr,n);
    int find=-1;
    search(find);
    if(search)
    {
        printf("the element is presentt");
    }
    else{
        printf("the element is noy present");
    }

}