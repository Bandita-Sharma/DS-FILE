#include<iostream>
#define max 5
using namespace std;
int front=-1;
int rear=-1;
int q[5];

void display()
{
    if(front==-1)
    {
        cout<<"queue empty";
    }
    if(rear>=front)
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<q[i]<<" ";
        }
    }
    else
    {
        for(int i=front;i<max;i++)
        {
            cout<<q[i]<<" ";
        }
        for(int i=0;i<=rear;i++)
        {
            cout<<q[i]<<" ";
        }
    }
      cout<<endl;
}

 void dequeue()
 {
     if(front==-1)
     {
         cout<<"empty queue";
     }
     if(front==rear)
     {
         front=-1;
         rear=-1;
     }
     else if(front==max-1)
     {
         front=0;
     }
     else
        front++;
 }

int enqueue(int num)
{
    if((front==0 && rear==max-1)||(rear==(front-1)%(max-1)))
    {
        cout<<"queue full";
        cout<<endl;
        return 0;
    }
    if(front==-1)
    {
        front=rear=0;
        q[rear]=num;
    }
    else if(rear==max-1 && front!=0)
    {
        rear=0;
        q[rear]=num;
    }
    else
    {
        rear++;
        q[rear]=num;
    }
}

int main()
{
    enqueue(14);
    enqueue(22);
    enqueue(13);
    enqueue(-6);
    display();
    dequeue();
    dequeue();
    display();
    enqueue(9);
    enqueue(20);
    enqueue(5);
    display();
    enqueue(20);
    display();
}
