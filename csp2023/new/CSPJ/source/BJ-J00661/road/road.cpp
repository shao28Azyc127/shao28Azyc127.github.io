#include<bits/stdc++.h>
using namespace std;
int n,s,d[100005],a[100005],dd=0,q[100005];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>s;
    for(int i=0;i<n-1;i++){
        cin>>d[i];
        q[i]=(d[i]+dd)/s-dd/s;
        if((d[i]+dd)%s>0)q[i]++;
        dd+=d[i];
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int id=0,as=q[0]*a[0];
    for(int i=1;i<n-1;i++){
        if(a[i]<a[id]) id=i;
        as+=a[id]*q[i];
    }
    cout<<as;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
