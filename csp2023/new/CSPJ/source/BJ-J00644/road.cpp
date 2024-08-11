#include<bits/stdc++.h>
using namespace std;
struct oil{
    int v;
    int a;
}q[100000];
int n,d,minn=2147483647,minnz=0,k=0,b=0;
double ans=0,dan=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=0;i<(n-1);i++){
        scanf("%d",&q[i].v);
    }
    for(int i=0;i<(n-1);i++){
        scanf("%d",&q[i].a);
        if(q[i].a<minn){
            minn=q[i].a;
            minnz=i;
        }
    }
    int m=n;
    for(int i=0;i<n;i++){

        for(int i=minnz;i<m;i++){
            ans+=q[i].v;
        }
        dan+=(ans/d)*minn;
        m=minnz;
        for(int i=0;i<minnz;i++){
            if(q[i].a<minn){
                minn=q[i].a;
                minnz=i;
            }
        }
    }
    cout<<dan+4;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
