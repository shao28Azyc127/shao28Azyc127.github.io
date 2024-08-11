#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6+10;
struct Node{
	int a=11,b;
	bool f=false;
}a[N];
bool cmp(Node x,Node y)
{
	if(x.a!=y.a)return x.a>y.a;
	return x.b<y.b;
}
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	a[n].a=1234;
	int t=n,pos=1,count=1,id=1;
	for(int i=1;i<=n;i++)a[i].b=i,a[i].a=10;
	while(a[pos].a!=0)
	{
		//cout<<"pos="<<pos<<endl<<"takeof:";
		if(a[count].a!=0)a[count].f=true;
		//cout<<a[count].b<<" ";
		if(a[count].a==1234)id=pos;
		a[count].a=0;
		sort(a+1,a+n+1,cmp);
		//cout<<endl;
		for(int i=1;i<=n;i++)cout<<a[i].b<<endl;
		if(count+2>n||a[count+1].f==true)
		{
			pos++;
			count=pos;
		}
		else
		{
			count+=1;
			if(count+1>n||a[count+1].f==true)
			{
				pos++;
				count=pos;
			}
			else
			{
				count++;
			}
		}
		//cout<<endl;
	}
	cout<<pos<<" "<<id<<endl;
	return 0;
}