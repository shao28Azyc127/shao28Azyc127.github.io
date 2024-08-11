#include<bits/stdc++.h>
using namespace std;
int a[20][20];
int numb[20];
int pass[10][100005];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
    int n,ans=0;
    scanf("%d",&n);
    for(int j=1;j<=n;j++){
        for(int i=1,k=10000;i<=5;i++,k/=10){
            scanf("%d",&a[j][i]);
            numb[j] += a[j][i]*k;
		}
    }
    for(int i=1;i<=n;i++){
        for(int j=1,f=10000;j<=5;j++,f/=10){
			for(int k=1;k<=9;k++){
				int idx = ((numb[i]/f)%10+k)%10;
				pass[i][numb[i]-(numb[i]/f)%10*f+idx*f]=true;
			}
		}
		for(int j=1,f=10000;j<=4;j++,f/=10){
			for(int k=1;k<=9;k++){
				int idx1 = ((numb[i]/f)%10+k)%10;
				int idx2 = ((numb[i]*10/f)%10+k)%10;
				pass[i][numb[i]-(numb[i]/f)%10*f-(numb[i]*10/f)%10*f/10+idx1*f+idx2*f/10]=true;
			}
		}
    }
    for(int i = 0;i<=99999;i++){
		bool able = true;
		for(int j=1;j<=n;j++)
			if(!pass[j][i]) able = false;
		if(able){
			ans++;
			//cout<<i<<" ";
		}
	}
	printf("%d",ans);
    return 0;
}
