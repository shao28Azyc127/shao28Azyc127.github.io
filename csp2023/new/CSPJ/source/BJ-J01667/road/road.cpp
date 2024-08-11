#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int a[N];
int m[N];
int l[N];
bool flag[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int sum=0;
    for(int i=1;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>m[i];
    }
    int ans=0;
    int dis=0;
    for(int i=1;i<n;i++){
        a[i]-=dis;
        if(a[i]%d==0){
            l[i]=a[i]/d;
            dis=a[i];
        }else {
            l[i]=a[i]/d+1;
            dis=d*l[i];
        }
        ans=ans+m[i]*l[i];
        dis-=a[i];
    }
    cout<<ans;
    return 0;
}
