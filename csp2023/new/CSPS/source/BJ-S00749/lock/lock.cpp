#include<bits/stdc++.h>
using namespace std;
int n,a[6],f[100001],cnt;
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int z=0;
		for(int j=1;j<=5;j++){
			scanf("%d",&a[j]);
			z=z*10+a[j];
		}
		for(int j=1;j<=5;j++){
			for(int k=1;k<=9;k++){
				int x=z-a[j]*(int)pow(10,5-j)+(a[j]+k)%10*(int)pow(10,5-j);
				int y=z-a[j]*(int)pow(10,5-j)+(a[j]-k+10)%10*(int)pow(10,5-j);
				f[x]+=1;
				f[y]+=1;
			}
		}
		for(int j=1;j<5;j++){
			for(int k=1;k<=9;k++){
				int x=z-a[j]*(int)pow(10,5-j)-a[j+1]*(int)pow(10,4-j)+(a[j]+k)%10*(int)pow(10,5-j)+(a[j+1]+k)%10*(int)pow(10,4-j);
				int y=z-a[j]*(int)pow(10,5-j)-a[j+1]*(int)pow(10,4-j)+(a[j]-k+10)%10*(int)pow(10,5-j)+(a[j+1]-k+10)%10*(int)pow(10,4-j);
				f[x]+=1;
				f[y]+=1;
			}
		}
	}
	for(int i=0;i<=99999;i++){
		if(f[i]==n*2){
			cnt++;
		}
	}
	printf("%d",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
