#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int dis[MAXN];
int a[MAXN];
int aqu[MAXN],head;
int n,amin=INT_MAX;
long long ans;
long long disall;
int d;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=2;i<=n;i++){
        cin>>dis[i];
    }
    long long addans;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        disall+=dis[i];
        if(a[i]<amin||i==n){
            if(disall%d==0){
                ans+=disall/d*a[head];
                disall=0;

            }
            else{
                addans=disall/d+1;
                disall=disall-(addans*d);
                ans+=addans*a[head];
            }
            head=i;
            amin=a[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}