#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e2+7;
const int MOD=1e7+7;
int n;
struct node
{
	string s;
	ll d,e;
};
node a[MOD];
ll st[N];
ll Hash(string s)
{
	ll ans=0;
	for(int i=0;i<s.length();i++)
	{
		ans*=10;
		ans%=MOD;
		ans+=int(s[i]-'a');
		ans%=MOD;
	}
	return ans;
}
int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	cin>>n;
	int temp=0;
	int t2=0;
	for(int i=1;i<=n;i++)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			string s;
			int k;
			cin>>s>>k;
		}
		else if(op==2)
		{
			string t,n;
			cin>>t>>n;
			a[Hash(n)].d=temp;
			a[Hash(n)].s=n;
			if(t=="int") temp+=4;
			else if(t=="short") temp+=2;
			else if(t=="byte") temp+=1;
			else if(t=="long") temp+=8;
			a[Hash(n)].e=temp;
		//	cout<<Hash(n)<<endl;
			t2++;
			st[t2]=Hash(n);
			cout<<a[Hash(n)].d<<endl;
		//	cout<<st[t2]<<endl;
		}
		else if(op==3)
		{
			string s;
			cin>>s;
			cout<<a[Hash(s)].d<<endl;
		}
		else if(op==4)
		{
			int addr;
			cin>>addr;
			bool flag=0;
			for(int j=1;j<=t2;j++)
			{
				if(a[st[j]].d>=addr && addr<=a[st[j]].e)
				{
					flag=1;
					cout<<a[st[j]].s<<endl;
				}
			}
			if(!flag) cout<<"ERR"<<endl;
		}
	}
	return 0;
}