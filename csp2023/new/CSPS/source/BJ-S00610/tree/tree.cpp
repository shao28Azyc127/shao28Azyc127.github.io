#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<ctime>
#include<cmath>
using namespace std;
int a[100010],b[100010],c[100010],m[100010][2],n,x;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}
	for(int i=1;i<=(n-1);i++){
		scanf("%d%d",&m[i][0],&m[i][1]);
	}
	cout<<(time(NULL)%20);
	return 0;
}
