#include <bits/stdc++.h>
using namespace std;
struct Lock{
	int num[5];
	/*bool operator(lock xx,lock yy){
		bool f=true;
		for(int i=0;i<5;i++) if(xx.num[i]!=yy.num[i]) f=false;
		return f;
	}*/
} a[10];
int cnt[81],ans;
vector <Lock>chance;
void find1(int pl){
	for(int i=0;i<5;i++){
		for(int j=0;j<9;j++){
			a[pl].num[i]=(a[pl].num[i]+1)%10;
			chance.push_back(a[pl]);
		}
		a[pl].num[i]=(a[pl].num[i]+1)%10;
	}
}
void find2(int pl){
	for(int i=0;i<4;i++){
		for(int j=0;j<9;j++){
			a[pl].num[i]=(a[pl].num[i]+1)%10;
			a[pl].num[i+1]=(a[pl].num[i+1]+1)%10;
			chance.push_back(a[pl]);
		}
		a[pl].num[i]=(a[pl].num[i]+1)%10;
		a[pl].num[i+1]=(a[pl].num[i+1]+1)%10;
	}
}
bool cmp(int i,int j){
	int f[5]={0,0,0,0,0},Cnt=0;
	for(int k=0;k<5;k++) f[k]=(a[i].num[k]+10-chance[j].num[k])%10;
	for(int k=0;k<5;k++) if(f[k]!=0) Cnt++;
	if(Cnt==1) return true;
	if(Cnt==2){
		for(int k=0;k<4;k++) if(f[k+1]==f[k]&&f[k]>0) return true;
	}
	return false;
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++){
			scanf("%d",&a[i].num[j]);
		}
	}
	find1(0);
	find2(0);
	for(int i=1;i<n;i++){
		for(int j=0;j<81;j++){
			if(cmp(i,j)){
				cnt[j]++;
			}
		}
	}
	for(int i=0;i<81;i++){
		if(cnt[i]==n-1) ans++;
	}
	printf("%d",ans);
	return 0;
}