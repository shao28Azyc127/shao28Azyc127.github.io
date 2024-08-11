#include<bits/stdc++.h>
using namespace std;
int di(int x){
	int ans=1;
	for(int i=2;i<=sqrt(x);i++){
		if(di%(i*i)==0)ans*=i;
	}
	return ans;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int a,b,c,d;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c;
        int d=b*b-4ac;
        if(d<0)cout<<"NO"<<endl;
        if(sqrt(d)*sqrt(d)==d){
			else if(max(-b+sqrt(d),-b-sqrt(d))%2==0){
				cout<<max((-b+sqrt(d))/2,(-b-sqrt(d))/2)<<endl;
			}
			else cout<<max((-b+sqrt(d)),(-b-sqrt(d)))<<'/'<<2<<endl;
		}
		else{
			if(b==0)b=0;
			else if(b%2==0)cout<<b/2<<'+';
			else cout<<b<<'/'<<2<<'+';
			if(di(d)==1)cout<<"sqrt("<<d<<')'<<'/'<<2<<endl;
			else if(di(d)%2==0)cout<<di(d)/2<<'*'<<"sqrt("<<d/di(d)/di(d)<<')'<<endl;
			else cout<<di(d)<<'*'<<"sqrt("<<d/di(d)/di(d)<<')'<</'<<2<<endl;
		}	
    }
    return 0;
 } 