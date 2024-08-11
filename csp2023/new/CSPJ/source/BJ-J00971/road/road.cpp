#include<bits/stdc++.h>
using namespace std;
int n,d,maxn=10000;
int a[20][20],s[20],o[20];
void road(int x,int y,int so){
	int l=0;
	if(x>n or y>n){
		return ;
	}
		for(int i=x;i<=y-1;i++){
			l+=s[i];
		}
		if(so>l){
			so=so-l;
			l=0;
		}
		else{
			l=l-so;
			so=0;
		}
		if(l%d==0){
			l=l/d;
		}
		else{
			so=(l/d+1)*d-l;
			l=l/d+1;
		}
	if(x==1 or y==1)
		a[x][y]=o[x]*l;
	else{
		a[x][y]=min(a[x-1][y],a[x-1][y-1]+o[x]*l);
	}
	road(x+1,y,so);
	road(x,y+1,so);
	return ;
}
int main(){
    popen("road.in","r");
    popen("road.out","w");    
    cin>>n>>d;
    for(int i=1;i<n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>o[i];
	}
	road(1,1,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[j][i]<<" ";
		}
		cout<<endl;
	}
	cout<<a[n-1][n];
return 0;
}
