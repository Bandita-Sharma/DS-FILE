#include<iostream>
using namespace std;

void satisfyheap(int a[],int i,int heapsize)
{
    int l,r,largest,temp;
    l=2*i;
    r=2*i+1;
    if(l<=heapsize && a[l]>a[i])
    {
        largest=l;
    }
    else
    {
        largest=i;
    }
    if(r<=heapsize && a[r]>a[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        satisfyheap(a,largest,heapsize);
    }
}

void buildheap(int a[],int len)
{
    int i,heapsize;
    heapsize=len-1;
    for(i=len/2;i>=0;i--)
    {
        satisfyheap(a,i,heapsize);
    }
}

void heapsort(int a[],int len)
{
    buildheap(a,len);
    int heapsize,i,temp;
    heapsize=len-1;
    for(i=heapsize;i>=0;i--)
    {
        temp=a[0];

        a[0]=a[heapsize];
        a[heapsize]=temp;
        heapsize--;
        satisfyheap(a,0,heapsize);
    }
    cout<<"After sorting:";
    for(i=0;i<len;i++)
    {
        cout<<"\t"<<a[i];
    }
}

int main()
{
    int a[30],i,n;
    cout<<"enter the size of array:";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    heapsort(a,n);
}

