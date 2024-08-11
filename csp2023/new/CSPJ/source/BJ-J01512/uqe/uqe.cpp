#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
	if(x<y)swap(x,y);
	if(y==0)return x;
	return gcd(y,y%x);
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int t,m,a,b,c,sj,fm,fz,yue;
	cin>>t>>m;
	while(t--){
		cin>>a>>b>>c;
		sj=b*b-4*a*c;
		if(sj<0){
			cout<<"NO\n";
			continue;
		}
		int sq=sqrt(sj);
		if(sq*sq==sj){
			fm=2*a;
			fz=-b+sq;
			yue=gcd(fm,fz);
			fm/=yue;fz/=yue;
			if((fz+fm-1)/fm>m){
				cout<<"NO\n";
				continue;
			}
			if(fm==1)cout<<fz<<'\n';
			else cout<<fz<<'/'<<fm<<'\n';
		}else cout<<"NO\n"<<endl;
		
	}
	return 0;
}
/*
(-b+sqrt(sj))/(2*a)
*/