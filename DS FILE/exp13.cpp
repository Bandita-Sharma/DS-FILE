//DFS
#include<iostream>
using namespace std;
int main() {
int v,e,orr,dst,s;
cin>>v>>e;
int adj[v][v];
for(int i=0;i<v;i++)
{
for(int j=0;j<v;j++)
{
adj[i][j]=0;
}
}
for(int i=1;i<=e;i++)
{
cin>>orr>>dst;
adj[orr][dst]=1;
}
cin>>s;
int top=-1;
int *st,*visited;
st=new int[v]();
visited =new int[v]();
if(!visited[s])
{
visited[s]=true;
}
top++;
st[top]=s;
while(top!=-1)
{
int ss=st[top];
cout<<ss<<" ";
top--;
for(int j=0;j<v;j++)
{
if(!visited[j] && adj[ss][j])
{
top++;
st[top]=j;
visited[j]=1;
}
}
}
return 0;
}
