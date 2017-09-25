#include <bits/stdc++.h>
using namespace std;
void segment_construct(int *arr,int left,int right,int pos);
int query(int *arr,int left,int right,int qleft,int qright,int pos);
void update(int *arr,int left,int right,int uleft,int uright,int data,int pos);
int tree[405];
int lazy[405];
int main() 
{
	int arr[100];
	memset(lazy,0,sizeof(lazy));
    int n,x,y,x1,y1,data;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	segment_construct(arr,0,n-1,0);
	for(int i=0;i<2*n-1;i++)
	printf("%d ",tree[i]);
	
	cout<<"update list "<<endl;
	cin>>x1>>y1>>data;		
	update(arr,0,n-1,x1,y1,data,0);	

	cout<<"ask query "<<endl;
	cin>>x>>y;
	int sum= query(arr,0,n-1,x,y,0);
	cout<<sum<<endl;
	for(int i=0;i<2*n-1;i++)
	printf("%d ",tree[i]);
}

void segment_construct(int *arr,int left,int right,int pos)
{
	if(left==right)
	{
		tree[pos]=arr[left];
		return;
	}
	int mid=(left+right)/2;
	segment_construct(arr,left,mid,2*pos+1);
	segment_construct(arr,mid+1,right,2*pos+2);
	tree[pos]=tree[2*pos+1]+tree[2*pos+2];
	
}

int query(int *arr,int left,int right,int qleft,int qright,int pos)
{
	if(lazy[pos]!=0)
	{
		tree[pos]+=(qright-qleft+1)*lazy[pos];
		if(left!=right)
		{
			lazy[2*pos+1]+=lazy[pos];
			lazy[2*pos+2]+=lazy[pos];
		}
		lazy[pos]=0;
	}


	if(qleft>=left && qright<=right)
		return tree[pos];
	if(qleft>right || qright<left)
		return 0;
	int mid=(left+right)/2;
	int x=query(arr,left,mid,qleft,qright,2*pos+1);
	int y=query(arr,mid+1,right,qleft,qright,2*pos+2); 
	return x+y;
}

void update(int *arr,int left,int right,int uleft,int uright,int data,int pos)
{
	if(lazy[pos]!=0)
	{
		tree[pos]+=(uright-uleft+1)*lazy[pos];
		if(left!=right)
		{
			lazy[2*pos+1]+=lazy[pos];
			lazy[2*pos+2]+=lazy[pos];
		}
		lazy[pos]=0;
	}
	if(uleft>right || uright<left)
	return;
	
	if(uleft>=left && uright<=right)
	{
		tree[pos]+=(uright-uleft+1)*data;
		if(left!=right)
		{
			lazy[2*pos+1]+=data;
			lazy[2*pos+2]+=data;
		}
		return;
	}
	int mid=(left+right)/2;
	update(arr,left,mid,uleft,uright,data,2*pos+1);
	update(arr,mid+1,right,uleft,uright,data,2*pos+2);
	tree[pos]=tree[2*pos+1]+tree[2*pos+2];
}











