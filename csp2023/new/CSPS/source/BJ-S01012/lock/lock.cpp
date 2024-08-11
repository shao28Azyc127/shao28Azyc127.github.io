#include<bits/stdc++.h>
using namespace std;
int mp[12][12][12][12][12],a[12][12],n;
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=5;++j)cin>>a[i][j];
		for(int j=1;j<=5;++j){
			for(int k=0;k<=9;++k){
				if(a[i][j]==k)continue;
				int tmp[6];
				for(int l=1;l<=5;++l){
					if(j==l)tmp[l]=k;
					else tmp[l]=a[i][l];
				}
				++mp[tmp[1]][tmp[2]][tmp[3]][tmp[4]][tmp[5]];
			}
		}
		for(int j=1;j<5;++j){
			for(int k=1;k<=9;++k){
				int tmp[6];
				for(int l=1;l<=5;++l){
					if(j==l||j+1==l)tmp[l]=(a[i][l]+k)%10;
					else tmp[l]=a[i][l];
				}
				++mp[tmp[1]][tmp[2]][tmp[3]][tmp[4]][tmp[5]];
			}
		}
	}
	int ans=0;
	for(int i=0;i<=9;++i)
		for(int j=0;j<=9;++j)
			for(int k=0;k<=9;++k)
				for(int l=0;l<=9;++l)
					for(int r=0;r<=9;++r)
						if(mp[i][j][k][l][r]==n)++ans;
	cout<<ans<<'\n';
	return 0;
}