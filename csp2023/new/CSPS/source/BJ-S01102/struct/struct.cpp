#include<bits/stdc++.h>
using namespace std;
struct lx{
	int s,a,b;//daxiao,yaoqiu,dizhi
	}l[207];
map<string,lx>siz;
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
int n,op,dj=0,cnt=0;
cin>>n;
siz["byte"]=(lx){1,1,-1};
siz["short"]=(lx){2,2,-1};
siz["int"]=(lx){4,4,-1};
siz["long"]=(lx){8,8,-1};
for(int i=0;i<n;i++){
cin>>op;
if(op==1){
int k,m=-1;
string s;
cin>>k;
cin>>s;
for(int j=0;j<k;j++){
string t,n;
cin>>t>>n;
m=max(m,siz[t].s);
}
cout<<m*k<<' '<<m<<endl;
siz[s].s=m*k;
siz[s].a=m;
siz[s].b=-1;
}
else if(op==2){
	string t,n;
	cin>>t>>n;
	l[cnt].s=siz[t].s;
	l[cnt].a=siz[t].a;
	l[cnt].b=dj;
	cnt++;
	cout<<dj<<endl;
	dj+=siz[t].s;
	}
else if(op==3){
	string s;
	cin>>s;
	cout<<siz[s].b<<endl;
	}
else{
	unsigned long long addr;
	cin>>addr;
	cout<<"err"<<endl;
	}}
return 0;
}