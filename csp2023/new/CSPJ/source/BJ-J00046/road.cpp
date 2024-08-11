#include<bits/stdc++.h>
using namespace std;
int n,d,v[100005],a[100005],s[100005],ans,sy;
int jc(int b,int e){
    int s1=s[e]-s[b]-sy;
    int m=s1/d;
    if(d*m<s1){
        m++;
    }
    ans+=m*a[b];
    return m;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d",&n,&d);
    for(int i=1;i<n;i++){
        scanf("%d",&v[i]);
        s[i+1]=s[i]+v[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int now=1;
    for(int i=1;i<=n;i++){
        if(a[now]>a[i]||i==n){
            sy+=jc(now,i)*d-s[i]+s[now];
            now=i;
        }
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
}
