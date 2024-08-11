#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n;
int a[10][10];
int tmp[10];
vector<int> d;
long long cnt = 0ll,cnt2 = 0ll;
bool check(int k){
	while(d.size() > 0)d.pop_back();
	for(int l=1;l<=5;l++){
		if(tmp[l] != a[k][l])d.push_back(l);
	}
	if(d.size() == 1)return 1;
	else if(d.size() == 2){
		if(d[0]+1 == d[1]){//xianglin
			if(tmp[d[0]]-a[k][d[0]]==tmp[d[1]]-a[k][d[1]] && tmp[d[0]]-a[k][d[0]]!=0)return 1;//fuduxiangtong
		}
	}
	return 0;
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++)scanf("%d",&a[i][j]);
	}
	if(n == 1){
		printf("81\n");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=5;i++)tmp[i] = a[1][i];
	for(int i=1;i<=5;i++){//zhuanyige
		for(int j=0;j<=9;j++){
			if(j == a[1][i])continue;
			tmp[i] = j;
			bool f = 1;
			for(int k=2;k<=n;k++)f = (f&&check(k));
			if(f){
				cnt++;
				//cout<<i<<" "<<j<<endl;
			}
			tmp[i] = a[1][i];
		}
	}
	//cout<<cnt<<endl;
	for(int i=1;i<=4;i++){//zhuanliangge
		for(int j=1;j<=9;j++){//fudu
			tmp[i] = (tmp[i]+j)%10;
			tmp[i+1] = (tmp[i+1]+j)%10;
			bool f = 1;
			for(int k=2;k<=n;k++)f = (f&&check(k));
			if(f){
				cnt2++;
				//cout<<i<<" "<<i+1<<" "<<tmp[i]<<" "<<tmp[i+1]<<endl;
			}
			tmp[i] = a[1][i];
			tmp[i+1] = a[1][i+1];
			
			tmp[i] = (tmp[i]+10-j)%10;
			tmp[i+1] = (tmp[i+1]+10-j)%10;
			f = 1;
			for(int k=2;k<=n;k++)f = (f&&check(k));
			if(f){
				cnt2++;
				//cout<<i<<" "<<i+1<<" "<<tmp[i]<<" "<<tmp[i+1]<<endl;
			}
			tmp[i] = a[1][i];
			tmp[i+1] = a[1][i+1];
		}
	}
	printf("%lld",cnt+cnt2/2);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
