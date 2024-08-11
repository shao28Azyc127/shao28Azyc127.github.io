#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1e5+10;
int a[N],v[N],s[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
        s[i+1]=v[i]+s[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long cnt=1,l=0,ans=0;
    while(cnt<n){
        int tmp=cnt+1,c=a[cnt];
        while(a[tmp]>=c){
            tmp++;
            if(tmp==n)break;
        }
        if(tmp>n)tmp=n;
        int dis=s[tmp]-s[cnt]-l;
        int k=ceil(1.0*dis/d);
        ans+=k*a[cnt];
        l=k*d-dis;
        //cout<<tmp<<" "<<a[cnt]<<" "<<a[tmp]<<" "<<dis<<" "<<ans<<" "<<l<<endl;
        cnt=tmp;

    }
    cout<<ans<<endl;
    return 0;
    fclose(stdin);
    fclose(stdout);
}

