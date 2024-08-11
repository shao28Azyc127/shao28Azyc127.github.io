#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#define LL long long

using namespace std;

bool flag[1000010];

int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin >> n;
	int ans1=0,ans2=0;
	bool jud=true;
	while(jud){
		jud=false;
		int cnt=0;
		ans1++;
		for(int j=1;j<=n;j++){
			if(flag[j])continue;
			jud=true;
			cnt++;
			if((cnt-1)%3==0){
				flag[j]=true;
				if(j==n)ans2=ans1;
			}
		}
	}
	cout << ans1-1 << " " << ans2 << endl;
}