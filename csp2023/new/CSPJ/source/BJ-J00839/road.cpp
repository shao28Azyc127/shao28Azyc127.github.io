#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int v[MAXN], a[MAXN], mins[MAXN];
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin>>n>>d;
    long long ans=0;
    for(int i=1;i<n;i++){
        scanf("%d", &v[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    mins[1]=a[1];
    for(int i=2;i<n;i++){
        mins[i]=min(mins[i-1], a[i]);
    }
    int y=0;
    for(int i=1;i<n;i++){
        int w=mins[i];
        v[i]-=y;
        int num=v[i]/d;
        if(v[i]%d!=0){
            num++;
            y=d-(v[i]%d);
        }
        else y=0;
        long long tmp=num*w;
        //cout<<v[i]<<" "<<tmp<<" "<<w<<endl;
        ans+=tmp;
        //cout<<ans<<endl;
    }
    cout<<ans;
    return 0;
}
