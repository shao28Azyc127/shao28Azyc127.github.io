#include<bits/stdc++.h>
using namespace std;
int x;
int n,ans=0,sum;
bool flag=0;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
    cin>>n;
    x=n;
    while(x!=0){
		x-=1;
		int y=x/3;
		x-=y;
		ans++;
		if((x-1)%3==0&&flag==0){
			sum=ans+1;
			flag=1;
		}
	}
	if((n-1)%3==0){
		sum=1;
	}
    cout<<ans<<" "<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
