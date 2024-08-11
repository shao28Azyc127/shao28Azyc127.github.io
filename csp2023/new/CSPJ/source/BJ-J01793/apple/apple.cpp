#include<bits/stdc++.h>
using namespace std;
int n,s,s1,ans;
bool f;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
cin>>n;
int p=n;
while(p!=0)
{
	s++;
	//if(p%3==0&&!f) ans=s,f=1;
	if(p>=3) 
	{p=p-double(p)/3.0;}
	else p--;
	//cout<<n<<endl;
}
p=n;
p--;
ans=1;
while(p%3!=0)
{
	if(p<3) 
	{ans+=p;break;}
	p-=(1+(p-1)/3);
	ans++;
	//cout<<ans<<endl;
}
//if(ans==0) ans=1;
cout<<s<<" "<<ans;
}
