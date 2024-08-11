#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=114514;

ll n;
ll cnt,dy;

int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	for (int i=1;n;i++)
	{
		cnt++;
		if (n%3==1&&!dy) dy=i;
		n-=((n-1)/3+1);
	}
	cout<<cnt<<' '<<dy<<endl;
	
	return 0;
}
