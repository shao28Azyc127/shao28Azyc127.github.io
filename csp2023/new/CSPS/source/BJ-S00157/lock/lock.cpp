#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<cstdio>
using namespace std;

int useadd(int x,int j,int k){
	int tmp=1;
	for(int r=1;r<=j;r++){
		tmp*=10;
	}
	if((x/tmp+k)/10%10!=x/tmp/10%10){
		return x+tmp*k-10*tmp;
	}
	else return x+tmp*k;
}
//a

int usedadd(int x,int j,int k){
	int tmp=1,y=useadd(x,j,k);
	for(int r=1;r<=j-1;r++){
		tmp*=10;
	}
	if((x/tmp+k)/10%10!=x/tmp/10%10){
		return y+tmp*k-10*tmp;
	}
	else return y+tmp*k;
}
//aa

int tot=0,ans=0;
int s[100005],a[10];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n;
	cin>>n;
	
	int x;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin>>x;
			a[i]=a[i]*10+x;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<5;j++){
			for(int k=1;k<=9;k++){
				s[++tot]=useadd(a[i],j,k);
				if(j>0){
					s[++tot]=usedadd(a[i],j,k);
				}
			}
		}
	}
	sort(s+1,s+tot+1);

	int tmp=0,cnt=0;
	for(int i=1;i<=tot;i++){
		if(tmp!=s[i]){
			if(cnt==n) ans++;
			tmp=s[i];
			cnt=1;
		}
		else cnt++;
	}
	if(cnt==n) ans++;
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
