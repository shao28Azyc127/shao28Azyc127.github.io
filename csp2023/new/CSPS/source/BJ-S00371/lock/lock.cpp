#include<bits/stdc++.h>
using namespace std;
bool h[100005];
int a[15],b[15],c[15],d[15],e[15],n;
bool dis(int aa,int bb,int cc,int dd){
	for(int i=1;i<=9;++i){
		aa=(aa+1)%10;bb=(bb+1)%10;
		if(aa==cc&&bb==dd)return 1;
	}
	return 0;
}
bool check(int aa,int bb,int cc,int dd,int ee){
	for(int i=1;i<=n;++i){
		if(aa==a[i]&&bb==b[i]&&cc==c[i]&&dd==d[i]&&ee==e[i])return 0;
		if(aa!=a[i]&&bb==b[i]&&cc==c[i]&&dd==d[i]&&ee==e[i])continue;
		if(aa==a[i]&&bb!=b[i]&&cc==c[i]&&dd==d[i]&&ee==e[i])continue;
		if(aa==a[i]&&bb==b[i]&&cc!=c[i]&&dd==d[i]&&ee==e[i])continue;
		if(aa==a[i]&&bb==b[i]&&cc==c[i]&&dd!=d[i]&&ee==e[i])continue;
		if(aa==a[i]&&bb==b[i]&&cc==c[i]&&dd==d[i]&&ee!=e[i])continue;
		int disab=dis(aa,bb,a[i],b[i]);
		int disbc=dis(bb,cc,b[i],c[i]);
		int discd=dis(cc,dd,c[i],d[i]);
		int disde=dis(dd,ee,d[i],e[i]);
		if(disab&&cc==c[i]&&dd==d[i]&&ee==e[i])continue;
		if(disbc&&aa==a[i]&&dd==d[i]&&ee==e[i])continue;
		if(discd&&aa==a[i]&&bb==b[i]&&ee==e[i])continue;
		if(disde&&aa==a[i]&&bb==b[i]&&cc==c[i])continue;
		return 0;
	}
	return 1;
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int aa,bb,cc,dd,ee,ans=0,i;
	cin>>n;
	for(i=1;i<=n;++i)cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i];
	for(aa=0;aa<=9;++aa){
		for(bb=0;bb<=9;++bb){
			for(cc=0;cc<=9;++cc){
				for(dd=0;dd<=9;++dd){
					for(ee=0;ee<=9;++ee){
						if(check(aa,bb,cc,dd,ee))ans++;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
