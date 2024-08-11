#include<bits/stdc++.h>
using namespace std;
int a[100050],b[100050];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,minn=199999,total=0,sum=0,ans=0;
    scanf("%d%d",&n,&d);
    for(int i=1;i<n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    for(int i=1;i<n;i++){
		if(b[i]<minn){
			minn=b[i];
			total=i;
		}
	}
	if(total==1){
		for(int i=1;i<n;i++)sum+=a[i];
		if(sum%d!=0) printf("%d",b[1]*(sum/d+1));
		else printf("%d",b[1]*sum/d);	
	}else{
		
	}
    return 0;
}
