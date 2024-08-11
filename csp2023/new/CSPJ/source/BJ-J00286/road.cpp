#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int v[N],a[N],s[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    bool flag=1;
    cin>>n>>d;
    for(int i=1; i<n; i++){
        cin>>v[i];
        s[i]=s[i-1]+v[i];
    }
    for(int i=1; i<=n; i++){
        cin>>a[i];
        if(a[i]<a[1]) flag=0;
    }
    if(n==1){
        cout<<0;
        return 0;
    }else if(n==2){
        cout<<ceil(v[1]/d)*a[1];
        return 0;
    }else if(n==3){
        if(a[1]<a[2]){
            cout<<ceil((v[1]+v[2])/d)*a[1];
        }else{
            cout<<ceil(v[1]/d)*a[1]+ceil(v[2]/d)*a[2];
        }
        return 0;
    }
    if(flag==1){
        cout<<ceil(s[n-1]/d)*a[1];
        return 0;
    }
    long long ans=0;
    int x,y=1,sheng=0;
    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){
            if(a[j]<a[i]){
                x=j;
                break;
            }
        }
        ans=ans+a[i]*ceil((s[x]-s[y])/d);
        sheng+=(ceil((s[x]-s[y])/d)*d-(s[x]-s[y]));
        i=x;
        y=x;
    }
    ans+=(s[n-1]-s[x]-sheng)*a[x];
    cout<<ans;
    return 0;
}
