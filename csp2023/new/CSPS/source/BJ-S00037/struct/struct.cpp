#include <bits/stdc++.h>
#define for0(i,n) for(i=0;i<(n);i++)
#define for1(i,n) for(i=1;i<=(n);i++)
#define forlr(i,l,r) for(i=(l);i<=(r);i++)
using namespace std;
const int N=100005;
int n;
bool b[N];
string s[N];
map<string,int> p,d;
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	int i,j,x,op;
	bool fl;
	string s1,s2;
	p["byte"]=1;
	p["short"]=2;
	p["int"]=4;
	p["long"]=8;
	cin>>n;
	for1(i,n){
		cin>>op;
		if(op==2){
			cin>>s1>>s2;
			x=p[s1];
			for(i=0;i<=100000;i+=x){
				fl=0;
				for0(j,x) if(b[i+j]) fl=1;
				if(fl){
					for0(j,x) b[i+j]=1,s[i+j]=s2;
					d[s2]=i;
					break;
				}
			}
		}
		if(op==3){
			cin>>s1;
			cout<<d[s1]<<endl;
		}
		if(op==4){
			cin>>x;
			if(!b[x]) cout<<"ERR"<<endl;
			else cout<<s[x]<<endl;
		}
	}
	return 0;
}
