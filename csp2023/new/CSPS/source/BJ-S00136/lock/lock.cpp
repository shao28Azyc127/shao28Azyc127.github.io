#include <bits/stdc++.h>
using namespace std;
int n,temp=0,ans=0,cnt=0;
int nums[10][10];
int a[10];
bool check(int a[],int b[]){
	int sum=0;
	int same[10];
	for(int i=1;i<=5;i++){
		if(a[i]!=b[i]){
			same[sum+1]=i;
			sum++;
		}
	}
	if(sum==1) return 1;
	if(sum>=3) return 0;
	if(abs(same[2]-same[1])==1 && ( a[same[1]] - b[same[1]] ) == ( a[same[2]] - b[same[2]] ) ){
		return 1;
	}else{
		return 0;
	}
}
void dfs(int pos){
	if(pos==6){
		for(int i=1;i<=n;i++){
			if(!check(a,nums[i])){
				return;
			}
		}
		ans++;
		return;
	}
	for(int i=0;i<=9;i++){
		a[pos]=i;
		dfs(pos+1);
	}
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>nums[i][1]>>nums[i][2]>>nums[i][3]>>nums[i][4]>>nums[i][5];
	}
	if(n==1){
		cout<<81;
		return 0;
	}
	dfs(1);
	cout<<ans;
    return 0;
    //我宣布，C C F是我ye ye
    //1 5:4 2 可能要A C了！！！1
    //ho ly
}
