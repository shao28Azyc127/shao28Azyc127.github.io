#include<cstdio>
using namespace std;
int n,cnt[100010];
int a[10];
void fig(){
	int res=a[1]*10000+a[2]*1000+a[3]*100+a[4]*10+a[5];
	//cout << res << endl;
	++cnt[res];
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=5; ++j)
			scanf("%d",a+j);
		for(int j=1; j<=5; ++j){
			for(int k=1; k<=9; ++k){
				a[j]=(a[j]+1)%10;
				fig();
			}
			a[j]=(a[j]+1)%10;
		}
		for(int j=1; j<=4; ++j){
			for(int k=1; k<=9; ++k){
				a[j]=(a[j]+1)%10;
				a[j+1]=(a[j+1]+1)%10;
				fig();
			}
			a[j]=(a[j]+1)%10;
			a[j+1]=(a[j+1]+1)%10;
		}
	}
	int ans=0;
	for(int i=0; i<=99999; ++i){
		if(cnt[i]==n)
			++ans;
	}
	printf("%d\n",ans);
	return 0;
}