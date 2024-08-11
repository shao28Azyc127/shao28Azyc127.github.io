#include<bits/stdc++.h>
using namespace std;
int a[100005],v[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n=0,d=0,ans=0;
    cin>>n>>d;
    for(int i=0;i<n-1;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int oil=0;
    for(int i=0;i<n-1;i+=0){
        int c=0,h=i+1;
        for(int j=i+1;j<n;j++){
            c+=v[j-1];
            h=j;
            if(a[j]<a[i]) break;
        }
        c-=oil;
        int f=c%d;
        if(f==0) f=d;
        ans+=((c+d-f)/d*a[i]);
        oil=d-f;
        i=h;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
