#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
struct num
{
	ll a, b;
	void fit()
	{
		ll p = __gcd(a,b);
		a = a/p;
		b = b/p;
	}
};
void pt(num t)
{
	if(t.b <0) {t.a *=-1;t.b*=-1;}
	if(t.b == 1) cout << t.a;
	else cout << t.a << "/" << t.b;
}
num add(num a,num b)
{
	num ans;
	ans.a=a.a*b.b +a.b*b.a;
	ans.b=a.b*b.b;
	ans.fit();
	return ans;
}
ll judge(ll a)
{
	ll ans = 1;
	for(ll i=2;i<=a;i++)
	{
		while(a%(i*i) == 0)
		{
			ans*=i;
			a /= i*i;
		}
	}
	return ans;
}
void solve(ll a,ll b,ll c)
{
	ll ans1,ans2,ans3,ans4;
	ll delta = b*b - 4*a*c;
	if (delta < 0)
	{
		cout << "NO" << endl;
		return ;
	}
	// -b/2a
	num ft,bk;
	ft.a=-b;
	ft.b=2*a;
	ft.fit();

	ll f = judge(delta);
	ll insqrt = delta/(f*f);
	bk.a=f;
	bk.b=2*a;
	//cout << "_" << delta <<endl;
	bk.fit();
	//cout << ft.a <<" " << ft.b <<" "<< bk.a <<" " << bk.b<<endl;
	if(insqrt == 0 or insqrt == 1)
	{
		bk.a*=insqrt;
		num ans =ft;
		if(a<0) bk.a=-bk.a;
		if (insqrt) ans = add(ft,bk);
		ans.fit();
		//cout <<"_ans" <<bk.a<<" "<<bk.b<<endl;
		if(ans.b == 1)
		{
			cout << ans.a << endl;
		}
		else{
			pt(ans);cout <<endl;
		}
	}
	else{
		if(ft.a!=0){pt(ft);cout <<"+";}
		if(a<0) bk.a=-bk.a;
		if(bk.a < 0 and bk.b<0)
		{
			bk.a =-bk.a;
			bk.b =-bk.b;
		}
		if(bk.b == 1)
		{
			if(bk.a == 1) cout <<"sqrt("<<insqrt<<")"<<endl;
			else cout << bk.a <<"*sqrt("<<insqrt<<")"<<endl;
		}
		else{
			if(bk.a == 1) cout <<"sqrt("<<insqrt<<")/"<<bk.b<<endl;
			else cout << bk.a <<"*sqrt("<<insqrt<<")/"<<bk.b<<endl;
		}
	}
}
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int t,sss;
	cin >> t >> sss;
	while(t --)
	{
		int a,b,c;
		cin >> a >> b >> c;
		solve(a,b,c);
	}
	return 0;
}