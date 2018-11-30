#include<iostream>
using namespace std;

int main()
{
    int n,i,flag=0;
    cin>>n;
    cout<<"enter the elements:"<<endl;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int num;
    cin>>num;
    for(i=0;i<n;i++)
    {
        if(a[i]==num)
        {
            cout<<i;
            flag=1;
            return 0;
        }
    }
     if(flag==0){
            cout<<"number not present";
        }
}
