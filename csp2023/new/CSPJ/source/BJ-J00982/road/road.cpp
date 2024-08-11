#include<bits/stdc++.h>
using namespace std;
long long q=0,p=1e9,e[100005],cnt=0,k=0,ans=0,lc=0,a,b,r=0,l=0,n[100005],m[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	cin>>a>>b;
	for(int i=1;i<=a-1;i++){
		cin>>n[i];
		e[i]=e[i-1]+n[i];
	} 
	for(int i=1;i<=a;i++){
		cin>>m[i];
	}
	for(int i=1;i<=a;i++){
		l=i;
		if(p>m[i]){
			if(lc>=e[l-1]){
				p=m[i];
				r=i;
				l=i;
			}else{
				q=e[l-1]-lc;
				k=q/b;
				if(q%b!=0&&lc+k*b<e[l-1]){
					k++;
				}
				ans+=k*p;
				lc+=k*b;
				p=m[i];
				r=i;
				l=i;
			}
		}
	}
	q=e[a-1]-lc;
	k=q/b;
	if(q%b!=0&&lc+k*b<e[a-1]){
		k++;
	}
	ans+=k*p;
	cout<<ans;
	return 0;
}
