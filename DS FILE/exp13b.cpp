//bfs
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
int *qu,*visited;
int f=0,r=0;
qu=new int[v]();
visited=new int[v]();
if(!visited[s])
{
visited[s]=true;
}
qu[r]=s;
r++;
while(f!=r)
{
int p=qu[f];
cout<<p<<" ";
f++;
for(int j=0;j<v;j++)
{
if(!visited[j] && adj[p][j])
{
qu[r]=j;
r++;
visited[j]=true;
}
}
}
return 0;
}
