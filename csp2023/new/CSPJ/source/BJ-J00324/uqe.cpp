#include<bits/stdc++.h>
using namespace std;
int gongshi(int a,int b,int c){
	int num=b*b-4*a*c;
	if(num<0)return -1;
	num=sqrt(num);
	int ans1=(-b-num)/(2*a),ans2=(-b+num)/(2*a);
	return max(ans1,ans2);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m,a,b,c,ans=0;
    scanf("%d%d",&t,&m);
	while(t--){
		scanf("%d%d%d",&a,&b,&c);
		ans=gongshi(a,b,c);
		if(ans!=-1)printf("%d\n",ans);
		else printf("NO\n");
	}
    return 0;
}
