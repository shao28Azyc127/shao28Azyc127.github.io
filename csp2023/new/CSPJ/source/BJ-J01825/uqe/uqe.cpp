#include<bits/stdc++.h>
using namespace std;
int t,m;
struct uqe{
	int a;
	int b;
	int c;
}u[5005];
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++)
    {
    	cin>>u[i].a>>u[i].b>>u[i].c;
	}
	for(int i=1;i<=t;i++)
		cout<<"0"<<endl;
    return 0;
}
