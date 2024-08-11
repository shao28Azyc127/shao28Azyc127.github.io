#include<iostream>
#include<cmath>
#include<cstdio>
typedef long long ll;
using namespace std;
struct Node{
    int l,money;
}a[100010];
int n,d;
int main(){
    int minn=0x7fffffff;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long ans=0;
    cin>>n>>d;
    int S=0;
    for(int i=2;i<=n;i++){
        cin>>a[i].l;
        S+=a[i].l;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i].money;
        minn=min(minn,a[i].money);
    }
    if(minn==a[1].money){
        cout<<ceil(S/(d*1.0))*minn<<endl;
        return 0;
    }
    long long s1=0;
    for(int i=1;i<n;){
        int m=a[i].money;
        int key=a[i].money;
        i++;
        long long s=a[i].l;
        while(i<=n&&a[i].money>key){
            s+=a[i].l;
            i++;
        }
        s-=s1;
        ans+=ceil(s/(d*1.0))*m;
        s1=s%d;
    }
    cout<<ans<<endl;
    return 0;
}
