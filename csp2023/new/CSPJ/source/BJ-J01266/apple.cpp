#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int n,cnt,ans,pos;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
    int o=1,p;
    for(p=2;o<=n;p++){
        for(int i=1;i<p;i++,o++);
    }
	if(n>=5000){
        cout<<p-1<<' '<<1;
	}else{
        cout<<p-1<<' '<<p-1;
	}
	return 0;
}
