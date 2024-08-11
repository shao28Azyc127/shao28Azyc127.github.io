#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int v[n];
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int minn=1000001;
    int s[n];
    int yu=0;
    s[0]=0;
    for(int i=1;i<n;i++){
        if(minn>a[i]){
            minn=a[i];
        }
        v[i]-=yu;
        int sheng;
        if((v[i]%d)!=0) sheng=v[i]/d+1;
        else sheng=v[i]/d;
        s[i]=minn*sheng+s[i-1];
        yu=sheng*d-v[i];
    }
    cout<<s[n-1];
    fclose(stdin);
    fclose(stdout);
    return 0;
}

