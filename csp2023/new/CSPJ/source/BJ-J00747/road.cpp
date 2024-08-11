#include <bits/stdc++.h>
using namespace std;
int main (){
    freopen ("road.in","r",stdin);
    freopen ("road.out","w",stdout);
    int n,d,v[100000],a[100000];
    scanf ("%d%d",&n,&d);
    for (int i=1;i<n;i++){
        scanf ("%d",&v[i]);
    }
    for (int i=0;i<n;i++){
        scanf ("%d",&a[i]);
    }
    int b=a[0];
    int c=0,e=0,i=1,ans=0;
    while (i<n){
        while (a[i]>=b){
            c+=v[i];
            //printf ("%d ",c);
            i++;
        }
        c+=v[i];
        //printf ("%d ",c);
        e=(c+d-1)/d;
        ans+=e*b;
        c-=e*d;
        //printf ("\n%d %d %d %d %d  %d %d\n",i+1,e,e*b,e*d,a[i],ans,c);
        b=a[i];
        i++;
    }
    printf ("%d",ans);
    return 0;
}
