#include <bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,q;
int X[504514],Y[504514];
int work()
{
	if(X[1]-Y[1] >= 0 and X[n] - Y[m] <= 0) return 0;
	if(X[1]-Y[1] <= 0 and X[n] - Y[m] >= 0) return 0;
	int i=1,j=1;
	int flag1=1,flag2=1;
	int lst = 0;
	unordered_map<int,int> mp;
	mp[0] = 1;
	for(int i=1;i<=n;i++)
	{	
		int fg = 0;
		for(int j=i;j<=m+1;j++)
		if((i==1 or mp[j]==i-1) and X[i] > Y[j])
			mp[j] = i,fg=1;
		if(!fg) {flag1=0;break;}
	}
	mp.clear();
	for(int i=1;i<=n;i++)
	{	
		int fg = 0;
		for(int j=i;j<=m+1;j++)
		if((i==1 or mp[j]==i-1) and X[i] < Y[j])
			mp[j] = i,fg=1;
		if(!fg) {flag2=0;break;}
	}
	
	return flag1 or flag2;
}
int work1()
{
	if(X[1]-Y[1] >= 0 and X[n] - Y[m] <= 0) return 0;
	if(X[1]-Y[1] <= 0 and X[n] - Y[m] >= 0) return 0;
	return 1;
}
struct op{
	int tp;int pos;int org;
};
int main(){
	ios::sync_with_stdio(false);
	cin .tie(0);
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin >> c >> n >> m >> q;
	if (c <= 2){
		for(int i =1;i<=n;i++) cin >> X[i];
		for(int i =1;i<=m;i++) cin >> Y[i];
		cout << work1();
		vector<op> ls;

		for(int k =1;k<=q;k++)
		{
			int kx,ky;
			cin >> kx >> ky;
			for(int j=1;j<=kx;j++)
			{
				int px,vx;
				cin >> px >> vx;
				op w;
				w.tp = 1;w.pos = px;w.org = X[px];
				X[px] = vx;
				ls.push_back(w);
			}
			for(int j=1;j<=ky;j++)
			{
				int py,vy;
				cin >> py >> vy;
				op w;
				w.tp = 2;w.pos = py;w.org = Y[py];
				Y[py] = vy;
				ls.push_back(w);
			}
			cout << work1();
			for(auto u:ls)
			{
				if(u.tp==1)
					X[u.pos] = u.org;
				else
					Y[u.pos] = u.org;
			}
			ls.clear();
		}
		return 0;
	}
	for(int i =1;i<=n;i++) cin >> X[i];
	for(int i =1;i<=m;i++) cin >> Y[i];
	cout << work();

	

	vector<op> ls;

	for(int k =1;k<=q;k++)
	{
		int kx,ky;
		cin >> kx >> ky;
		//cout << " " << kx << " " << ky<<endl;
		for(int j=1;j<=kx;j++)
		{
			int px,vx;
			cin >> px >> vx;
			op w;
			w.tp = 1;w.pos = px;w.org = X[px];
			X[px] = vx;
			ls.push_back(w);
		}
		for(int j=1;j<=ky;j++)
		{
			int py,vy;
			cin >> py >> vy;
			op w;
			w.tp = 2;w.pos = py;w.org = Y[py];
			Y[py] = vy;
			ls.push_back(w);
		}

		// cout << endl;
		// for(int j=1;j<=n;j++) cout << X[j] << " ";
		// cout << endl;
		// for(int j=1;j<=m;j++) cout << Y[j] << " ";	
		// cout << endl;
		cout << work();
		for(auto u:ls)
		{
			if(u.tp==1)
				X[u.pos] = u.org;
			else
				Y[u.pos] = u.org;
		}
		ls.clear();
	}
	return 0;
}