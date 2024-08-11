#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,p[100005]={},s[100005]={},z=0,l=0;
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n-1;i++){
        scanf("%d",&s[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
        if(p[i-1]<p[i]&&i!=1){
            p[i]=p[i-1];
        }
    }
    for(int i=1;i<=n-1;i++){
        if(l>=s[i]){
            l-=s[i];
        }else{
            int c=((s[i]-l)/d*d==(s[i]-l)?(s[i]-l)/d:(s[i]-l)/d+1);
            l+=c*d;
            l-=s[i];
            z+=c*p[i];
        }
    }
    printf("%d",z);
}
