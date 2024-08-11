#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int d,n,mix=92100,z=0,ans=0,m=1,j=0;
    float e;
    printf("%d%d",&n,&d);
    int v[n],a[n+1],b[n+1];
    for(int i=1;i<n;i++) scanf("%d",&v[i]),z+=v[i];
    for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]<mix) mix=a[i];
    }
    if(a[1]==mix) {
        e=z/d*a[1];
        ans=ceil(e);
        printf("%d",ans);
        return 0;
    }
    for(int i=1;i<=n;i++) b[i]=a[i];
    for(int i=1;i<=n;i++){
        j=i;
        while(b[j]<b[j-1]){
            int t=b[j-1];
            b[j-1]=b[j];
            b[j]=t;
            j++;
        }
    }
    for(int i=1;i<=n;i++){
    while(a[m]<a[m+1]){
        j++;
        m++;
    }
    }
    fclose(stdin);
    fclose(stdout);
}