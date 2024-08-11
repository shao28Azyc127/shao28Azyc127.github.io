//Genshin Impact (wrong) Zhenshen Impart (true)
//I love Kamisato Ayaka
#include <bits/stdc++.h>
#define rep(i,a,b,c) for(int (i)=a;i<=(b);i+=(c))
#define per(i,a,b,c) for(int (i)=a;i>=(b);i-=(c))
using namespace std;
int a[10][6];
int ans=0,n;
int cur[6];
int cmp(int i){
	rep(j,1,5,1)	if(a[i][j]!=cur[j])	return 1;
	return 0;
}	
int main(){

	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	rep(i,1,n,1)	rep(j,1,5,1)	cin>>a[i][j];
	rep(x,0,9,1)	rep(b,0,9,1)	rep(c,0,9,1)	rep(d,0,9,1)	rep(e,0,9,1){
		cur[1]=x;cur[2]=b;cur[3]=c;cur[4]=d;cur[5]=e;
		int flg=1;
		rep(i,1,n,1)	flg=flg&cmp(i);
		rep(i,1,n,1){
			int cc=-1,cnt=0;
			rep(j,1,5,1){
				if(a[i][j]!=cur[j] && cc==-1)	cc=(a[i][j]-cur[j]+10)%10,cnt=j;
				else if(a[i][j]!=cur[j]&& cc!=-1){	
					if(	(a[i][j]-cur[j]+10)%10!=cc || cnt!=j-1){
						flg=0;break ;
					}
				}
			}
			if(!flg)	break ;
		}
		ans+=flg;
	}	
	cout<<ans<<endl;
	return 0;
}