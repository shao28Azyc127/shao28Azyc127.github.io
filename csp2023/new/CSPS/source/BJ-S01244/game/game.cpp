#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int n;
string S;
int f[8010][8010];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin >> n;
	cin >> S;
	ll ans = 0;
	S = "0" + S;
	for(int k = 1;k<n;k+=2)
	{
		for(int i=1;i+k<=n;i++)
		{
			if(S[i] == S[i+k] and k == 1) { if(k==1) {f[i][i+k] = 1;ans++;}}
			else{
				if(k%2==1 and k!=1){
				if(S[i] == S[i+k] and f[i+1][i+k-1] == 1  and f[i][i+k] == 0)
					{
						f[i][i+k] = 1;
						ans ++;
						//cout << "B" << i << " " << k+i << endl;
					}
				}
			}
			if(f[i][i+k] == 0)
			if(k>=3)
			{
				for(int j=i+1;j+1<i+k;j++)
				{
					if(f[i][j] == 1 and f[j+1][i+k] == 1 and f[i][i+k] == 0)
					{
						f[i][i+k] = 1;
						//cout << "C"  << i << " " << k+i << " "<< j<< endl;
						ans ++;
						break; 
					}
				}
			}
		}
	}
	cout << ans;
}