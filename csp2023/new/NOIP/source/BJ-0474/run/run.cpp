#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <vector>
#include <cstdio>
using namespace std;
long long c,t;
long long n,m,k,d;
struct task{
long long x,y,z;
}a[100005];
bool cmp(task o,task p){
	return o.x<p.x;
}
long long f[1005][1005];//first i task j day max value
//f[i][j]=max(f[i][j-1],f[i-1][j-a[i].y]-a[i].y*d+a[i].z);
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    while(t--){
		cin>>n>>m>>k>>d;
		for(int i = 1;i<=m;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		sort(a+1,a+m+1,cmp);
		for(int i = 0;i<=m;i++){
			for(int j = 0;j<=n;j++){
				f[i][j]=0;
			}
		}
		for(int i = 1;i<=m;i++){
			for(int j = 1;j<=n;j++){
				if(a[i].x==j&&a[i].y<=k&&a[i].z>a[i].y){
					f[i][j]=max(f[i][j-1],f[i-1][j-a[i].y]-a[i].y*d+a[i].z);
				}else{
					f[i][j]=f[i-1][j];
				}
			}
		}
		cout<<f[m][n]<<endl;
	}
    return 0;
}
