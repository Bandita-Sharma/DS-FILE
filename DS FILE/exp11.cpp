#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
}*root=NULL;

void insert(int num)
{
    node *new_node=new node;
    new_node->data=num;
    new_node->left=NULL;
    new_node->right=NULL;
    if(root==NULL)
    {
        root=new_node;
        return ;
    }
    node *temp=root;
    while(1)
    {
        if(new_node->data<temp->data)
        {
            if(temp->left)
            {
                temp=temp->left;
            }
            else
            {
                temp->left=new_node;
                break;
            }
        }
        else if(temp->right)
        {
            temp=temp->right;
        }
        else
        {
            temp->right=new_node;
            break;
        }
    }
}

void preorder(node *root)
{
   node *temp=root;
   if(root==NULL)
   {
       //cout<<"tree is empty";
       return;
   }
       cout<<temp->data<<"->";
       preorder(temp->left);
       preorder(temp->right);
}

node* FindMin(node *root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

node* delete1(node *root,int data)
{
    if(root==NULL)
    {
        return root;
    }

    else if(data<root->data)
        root->left=delete1(root->left,data);
        else if(data>root->data)
        root->right=delete1(root->right,data);
    else
    {
        //case1:no child
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            root=NULL;
        }
        //cse2:one child
        else if(root->left==NULL)
        {
            node *temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right==NULL)
        {
            node *temp=root;
            root=root->left;
            delete temp;
        }
        //case3:two child
        else
        {
            node *temp=FindMin(root->right);
            root->data=temp->data;
            root->right=delete1(root->right,temp->data);
        }
    }
    return root;
}

int main()
{
    int n;
    cout<<"enter the number of elements:";
    cin>>n;
    node *root1;
    int i;
    int num;
    cout<<"enter the elements:";
    for(i=0;i<n;i++)
    {
        cin>>num;
        insert(num);
    }
    preorder(root);
    int ele;
    cout<<"Enter the element you want to delete:";
    cin>>ele;
    root1=delete1(root,ele);
    preorder(root1);
}

