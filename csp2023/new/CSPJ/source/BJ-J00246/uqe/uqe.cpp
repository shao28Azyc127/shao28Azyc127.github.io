#include<iostream>
#include<cmath>
using namespace std;
struct frac{int p, q, x;};
struct sqt{int p, q;};
sqt getsqt(int a)
{
	int x;
	for(int i = floor(sqrt(a)); i > 0; i--)
	{
		if(a%(i*i) == 0)
		{
			x = i;
			break;
		}
	}
	return {x, a/(x*x)};
}
int gettgcd(int p, int q)
{
	if(q==0) return p;
	return gettgcd(q, p%q);
}
frac huajian(frac a)
{
	frac ans = {0, 0, 1};
	if(a.p < 0 && a.q >= 0) ans.x = -1;
	if(a.p >= 0 && a.q < 0) ans.x = -1;
	a.p = abs(a.p);a.q = abs(a.q);
	int x = gettgcd(a.p, a.q);
	ans.p = a.p/x;ans.q = a.q/x;
	return ans;
}
string frac2string(frac x)
{
	string tmp = "-"+to_string(x.p);
	if(x.p == 0) tmp = "0";
	if(x.q == 1 && x.x == -1) return tmp;
	if(x.q == 1 && x.x == 1) return to_string(x.p);
	if(x.x == -1) return tmp + "/" + to_string(x.q);
	return to_string(x.p) + "/" + to_string(x.q);
}
string frac2string(frac x, int p)
{
	if(p==0) return "0";
	string tmp = to_string(x.p)+"*";
	if(x.p == 1) tmp = "";
	if(x.q == 1) return tmp+"sqrt("+to_string(p)+")";
	return tmp +"sqrt("+to_string(p)+")" + "/" + to_string(x.q);
}
string calcabc(int a, int b, int c)
{
	int x = b*b-4*a*c;
	if(x < 0) return "NO";
	sqt y = getsqt(x);
	if(y.q == 1)
	{
		if(a < 0) return frac2string(huajian({min(-b+y.p, -b-y.p), 2*a}));
		return frac2string(huajian({max(-b+y.p, -b-y.p), 2*a}));
	}
	frac ans1 = huajian({-b, 2*a}), ans2 = huajian({y.p, 2*a});
	//ans1: -b/2a
	//ans2: sqrt(x).p/2a
	//ret -b + sqrt(x)/2a
	string x22 = frac2string(ans1);
	string x33 = frac2string(ans2, y.q);
	if(x22 == "0" && x33 != "0") return x33;
	if(x22 != "0" && x33 == "0") return x22;
	if(x22 == "0" && x33 == "0") return "0";
	return x22+"+"+x33;
}
int main()
{
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	int n, m;
	cin>>n>>m;
	//cout<<"sqrt("<<n<<") = "<<getsqt(n).p<<"*sqrt("<<getsqt(n).q<<")";
	for(int i = 1; i <= n; i++)
	{
		int a, b, c;
		cin>>a>>b>>c;
		cout<<calcabc(a, b, c)<<endl;
	}
}
