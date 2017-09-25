#include<bits/stdc++.h>
using namespace std;
int BIT[10000];        //binary indesxed tree;
int arr[10000];
int n;
void update(int x,int val)
{
	for(;x<=n;x+=x&-x)            // -x gives 2's complement , x& -x gives and between x && 2's of x then x+=x&-x gives next node to update
		BIT[x]+=val;
}

int query(int x)
{
	int sum=0;
	for(;x>0;x-=x&-x)
		sum+=BIT[x];               // -x gives 2's complement , x& -x gives and between x && 2's of x then x-=x&-x gives parent node of x
	return sum;

}

main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		update(i,arr[i]);	
	}
	int x=query(7);           // it will give sum between(1,7)
	printf("%d",x);

}
