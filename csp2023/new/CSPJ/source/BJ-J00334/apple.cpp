#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	int ans=0,cnt=0,q=n,st=1,s=n,w=n;
	bool nz=1;
	while(q>0){
		ans++;
		if(nz){
			cnt++;
		}
		int jian=0;
		for(int i=st; i<=s; i+=3){
			n--;
			cout<<"i="<<i<<endl;
			if(i==n){
				nz=0;
				cnt++;
			}
			q--;
			jian++;
		}
		s-=jian;
		//cout<<"s="<<s<<" "<<"nz="<<nz<<" "<<"n="<<n<<" "<<"q="<<q<<" "<<"cnt="<<cnt<<" "<<"ans="<<ans<<endl;
	}
	if(w%3==0 && w!=3){
		cnt--;
	}
	if((w-1)%3==0){
		cout<<ans<<" "<<1;
	}
	else{
		cout<<ans<<" "<<cnt;
	}
	return 0;
}
