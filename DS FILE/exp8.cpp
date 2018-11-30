#include<iostream>
using namespace std;
void insertionsort(int a[],int n)
{
     for(i=1;i<=n-1;i++)
    {
        temp=a[i];
        j=i-1;
        while((temp<a[j])&&(j>=0))
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
        cout<<"Pass"<<i<<":";
        for(j=0;j<n;j++)
        {
            cout<<a[j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int i,a[20],n;
    cout<<"Enter no of elements in an array: ";
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    insertionsort(a,n);
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    int item;
    cout<<"\nEnter ITEM to be inserted : ";
     cin>>item;
     i = n-1;
     while(item<a[i] && i>=0)
     {
           a[i+1] = a[i];
           i--;
     }
     a[i+1] = item;
     n++;
     cout<<"\nAfter insertion array is :\n";
      for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

}
