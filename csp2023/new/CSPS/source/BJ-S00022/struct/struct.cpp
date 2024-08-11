#include <bits/stdc++.h>
using namespace std;
struct name{
	int l,front;
	char c[15];
} a[110];
int f,now,cnt,xx,n;
char x[15];
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	cin>>n;
	for(int k=0;k<n;k++){
		cin>>f;
		if(f==2){
			cin>>x>>a[cnt].c;
			if(x[0]=='b') a[cnt].l=1;
			if(x[0]=='s') a[cnt].l=2;
			if(x[0]=='i') a[cnt].l=4;
			if(x[0]=='l') a[cnt].l=8;
			if(now%a[cnt].l==0) a[cnt].front=now;
			else a[cnt].front=now-now%a[cnt].l+a[cnt].l;
			now=a[cnt].front+a[cnt].l;
			cout<<a[cnt].front<<endl;
			cnt++;
		}
		if(f==3){
			cin>>x;
			for(int i=0;i<cnt;i++){
				if(a[i].c==x) cout<<a[i].front<<endl;
			}
		}
		if(f==4){
			cin>>xx;
			for(int i=0;i<cnt;i++){
				if(a[i].front<=xx&&a[i].front+a[i].l-1>=xx){
					cout<<a[i].c<<endl;
					break;
				}
			}
			cout<<"ERR"<<endl;
		}
	}
	return 0;
}