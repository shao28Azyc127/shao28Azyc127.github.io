#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	bool flag=true;
	long long cnt=1;
	long long ans;
	while(n>0){
        //cout<<n<<" "<<cnt<<" "<<ans<<endl;
        if(n%3==1&&flag){
            ans=cnt;
            flag=false;
        }
        n=n-n/3-(n%3!=0);
        cnt++;
	}
	cout<<cnt-1<<" "<<ans<<endl;
	return 0;
}
