#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,m,a[5005],b[5005],c[5005],tmp1,tmp2,tmp3,tmp4,tmp5,tmp6,tmp7,lt1,lt2,lt3;
ll q1,q2,q3;
ll gcd(ll x,ll y)
{
	if(x==0)return y;
	return gcd(y%x,x);
	}
ll f(ll x)
{
	if(x==0)return 0;
	if(x==1)return 1;
	if(x==2)return 1;
	ll i=2,rt=1;
	while(i<=x)
	{
		while(x&&x%(i*i)==0)
		{
			x/=(i*i);
			rt*=i;
		}
		i++;
	}
	return rt;
	}
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>t>>m;
	for(int i=1;i<=t;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		tmp1=b[i]*b[i]-4*a[i]*c[i];
		if(tmp1<0)
		{
			cout<<"NO\n";
			continue;
			}
		tmp2=2*a[i];
		tmp7=tmp2;
		tmp3=-1*b[i];
		tmp4=gcd(abs(tmp2),abs(tmp3));
		if(tmp2*tmp3<0)q1=-1;
		else q1=1;
		tmp2=abs(tmp2)/tmp4,tmp3=abs(tmp3)/tmp4;
		/*if(tmp3%tmp2==0)
		{
			cout<<tmp3/tmp2;
		}
		else
		{
			cout<<tmp3<<"/"<<tmp2;
		}*/
		tmp5=f(tmp1);
		if(tmp5)
		tmp1/=tmp5*tmp5;
		tmp6=gcd(abs(tmp5),abs(tmp7));
		if(tmp5*tmp7<0)q2=1;
		else q2=1;
		tmp5=abs(tmp5)/tmp6,tmp7=abs(tmp7)/tmp6;
		/*if(tmp5%tmp7==0)
		{
			cout<<tmp5/tmp7;
		}
		else
		{
			cout<<tmp5<<"/"<<tmp7;
		}*/
		//q1=tmp3/tmp2*q1
		//q2=tmp5/tmp7*q2
		if(tmp1==1)
		{
			lt1=(q1*tmp3*tmp7+q2*tmp2*tmp5);
			lt2=(tmp2*tmp7);
			lt3=gcd(abs(lt1),abs(lt2));
			if(lt1*lt2<0)cout<<'-';
			lt1=abs(lt1)/lt3,lt2=abs(lt2)/lt3;
			if(lt1%lt2==0)cout<<lt1/lt2;
			else
			{
				cout<<lt1<<'/'<<lt2;
				}
		}
		else
		{
			if(tmp3!=0)
			{
			if(q1==-1)cout<<'-';
			if(tmp3%tmp2==0)
			{
				cout<<tmp3/tmp2;
			}
			else
			{
				cout<<tmp3<<"/"<<tmp2;
			}
			}
			if(tmp1==0)
			{if(tmp3!=0)cout<<'\n';
				else cout<<"0\n";
				continue;}
			if(tmp3!=0)cout<<'+';
			if(tmp5%tmp7==0)
			{
				if(tmp5/tmp7>1)
				cout<<tmp5/tmp7<<'*';
				cout<<"sqrt("<<tmp1<<")";
			}
			else
			{
				if(tmp5>1)cout<<tmp5<<"*";
				cout<<"sqrt("<<tmp1<<")/"<<tmp7;
			}
		}
		cout<<'\n';
	}
return 0;	
}
