#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
struct q{
	int num;
	string s;
};
string s[3010];
q t[3010];

string work(string s)
{
	sort(s.begin(),s.end());
    reverse(s.begin(),s.end());
	return s;
}

string work2(string s)
{
	sort(s.begin(),s.end());
	return s;
}
bool cmp(q a,q b){
	return a.s < b.s;
}
int main(){
	
	ios::sync_with_stdio(false);
	cin .tie(0);
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin >> n >> m;
	for(int i =1;i<=n;i++)	
	{
		cin >> s[i];
		t[i].s = work(s[i]);
		t[i].num = i;
	}
	sort(t+1,t+1+n,cmp);
	//for(int i =1;i<=n;i++)	
	//	cout << t[i].num << " " << t[i].s << endl;
	for(int i =1;i<=n;i++)	
	{
		if(work2(s[i]) >= t[1].s and t[1].num != i)	cout << 0;
		else cout << 1;
	}
	return 0;
}