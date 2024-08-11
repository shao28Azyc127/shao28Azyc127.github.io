#include<iostream>
#include<vector>
using namespace std;
int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int n, c=0, ans=0;
	cin>>n;
	vector<int> x(n,0);
	for(int i = 0; i < n; i++) x[i] = i+1;
	while(x.size())
	{
		c++;
		if((x.size()-1)%3==0&&ans==0)
			ans=c;
		for(int i = 0; i < (int)x.size(); i+=3) x[i] = -1;
		vector<int> t;
		for(int i = 0; i < (int)x.size(); i++)
			if(x[i] != -1)
				t.push_back(x[i]);
		x = t;
	}
	cout<<c<<" "<<ans;
}
