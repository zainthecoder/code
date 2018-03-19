#include <iostream>
#include <limits.h>
using namespace std;


void builtTree(int *tree,int *a,int index,int s,int e)
{
    if(s>e)return;
    
    if(s==e)
    tree[index]=a[s];
    return;
    
    //recursive case
    int mid=(s+e)/2;
    
    builtTree(tree,a,2*index,s,mid);
    builtTree(tree,a,2*index+1,mid+1,e);
    
    int left=tree[2*index];
    int right=tree[2*index+1];
    
    tree[index]=min(left,right);

    
}


int query(int *tree,int index,int s,int e,int qs,int qe)
{
    
    if(qs>e || qe<s)
    return INT_MAX;
    
    if(s>=qs && e<=qe)
    return tree[index];
    
    int mid=(s+e)/2;
    int leftAns=query(tree,2*index,s,mid,qs,qe);
    int rightAns=query(tree,2*index+1,mid+1,e,qs,qe);
    
   return min(leftAns,rightAns);
    
    
}


int main() {
    
    int a[]={1,3,2,-2,4,5};
    int n=6; 
    
    //build tree array
    int index=1;
    int s=0;
    int e=n-1;
    
    int no_of_q;
    cin>>no_of_q;
    
    int *tree=new int[4*n+1];
    builtTree(tree,a,1,0,n-1);
    
    while(no_of_q--)
    {int qs,qe;
        cin>>qs>>qe;
        
        cout<<query(tree,index,s,e,qs,qe)<<endl;
        
    }
    
    return 0;
    
    
}
