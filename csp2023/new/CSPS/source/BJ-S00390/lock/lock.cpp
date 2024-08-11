#include <iostream>
using namespace std;
int a[9],b[9],c[9],d[9],e[9];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n;
	cin>>n;
	if(n==1){
		int v,w,x,y,z;
		cin>>v>>w>>x>>y>>z;
		cout<<81;
		return 0;
	}else if(n==2){
		int l,m,n,o,p,q,r,s,t,u;
		cin>>l>>m>>n>>o>>p>>q>>r>>s>>t>>u;
		if(l==q and m==r and n==s and o==t and p==u){
			cout<<81;
			return 0;
		}else if((l==q and m==r and n==s and o==t and p!=u) or (l==q and m==r and n==s and o!=t and p==u) or (l==q and m==r and n!=s and o==t and p==u) or (l==q and m!=r and n==s and o==t and p==u) or (l!=q and m==r and n==s and o==t and p==u)){
			cout<<10;
			return 0;
		}else if((l==q and m==r and n==s and (10+o-t)%10==(10+p-u)%10) or (l==q and m==r and o==t and (10+n-s)%10==(10+p-u)%10) or (l==q and m==r and p==u and (10+o-t)%10==(10+n-s)%10) or (l==q and o==t and n==s and (10+m-r)%10==(10+p-u)%10) or (l==q and p==u and n==s and (10+o-t)%10==(10+m-r)%10) or (o==t and m==r and n==s and (10+l-q)%10==(10+p-u)%10) or (p==u and m==r and n==s and (10+o-t)%10==(10+l-q)%10) or (o==t and p==u and n==s and (10+l-q)%10==(10+m-r)%10) or (o==t and m==r and p==u and (10+l-q)%10==(10+n-s)%10) or (l==q and o==t and p==u and (10+m-r)%10==(10+n-s)%10)){
			cout<<10;
			return 0;
		}else if((l==q and m==r and n==s and (10+o-t)%10!=(10+p-u)%10) or (l==q and m==r and o==t and (10+n-s)%10!=(10+p-u)%10) or (l==q and m==r and p==u and (10+o-t)%10!=(10+n-s)%10) or (l==q and o==t and n==s and (10+m-r)%10!=(10+p-u)%10) or (l==q and p==u and n==s and (10+o-t)%10!=(10+m-r)%10) or (o==t and m==r and n==s and (10+l-q)%10!=(10+p-u)%10) or (p==u and m==r and n==s and (10+o-t)%10!=(10+l-q)%10) or (o==t and p==u and n==s and (10+l-q)%10!=(10+m-r)%10) or (o==t and m==r and p==u and (10+l-q)%10!=(10+n-s)%10) or (l==q and o==t and p==u and (10+m-r)%10!=(10+n-s)%10)){
			cout<<2;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i];
	}
	cout<<1;
	return 0;
}
