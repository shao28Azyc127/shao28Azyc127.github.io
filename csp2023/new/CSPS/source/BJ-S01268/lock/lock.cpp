#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long n;
long long s[10][7], a[7];
long long ans;
int vis[7];

bool check(ll x) {
    ll cnt=0;
    for(ll i=1; i<=5; i++) vis[i]=0;

    for(ll i=1; i<=5; i++) {
    //    cout<<a[i]<<" ";
        if(a[i]!=s[x][i]) {
            cnt++;
            vis[i]=1;
        }
    }
  //  cout<<endl<<cnt<<endl;


  //  for(ll i=1; i<=5; i++) cout<<vis[i]<<" ";cout<<endl;

    if(cnt==1) return 1;
    if(cnt>=3 || cnt==0) return 0;

    ll p=0;
    for(ll i=1; i<=5 && p==0; i++)
        if(vis[i]==1) {
            p=i;
        }

  //  cout<<p<<endl;

    if(vis[p+1]==0) return 0;

    ll r1=a[p], r2=a[p+1];
    ll w1=s[x][p], w2=s[x][p+1];

  //  cout<<r1<<" "<<r2<<" "<<w1<<" "<<w2<<endl;

    if(r1<r2) r1+=10;
    if(w1<w2) w1+=10;

    if(r1-r2==w1-w2) return 1;



    else return 0;
}

int main() {
    freopen("lock.in","r",stdin);
    freopen("lock.out", "w", stdout);

    scanf("%lld", &n);

    for(long long i=1; i<=n; i++)
        for(long long j=1; j<=5; j++) scanf("%lld", &s[i][j]);


    for(a[1]=0; a[1]<=9; a[1]++) {
        for(a[2]=0; a[2]<=9; a[2]++) {
            for(a[3]=0; a[3]<=9; a[3]++) {
                for(a[4]=0; a[4]<=9; a[4]++) {
                    for(a[5]=0; a[5]<=9; a[5]++) {
                        bool f=1;
                        for(ll i=1; i<=n && f; i++) {
                            if(!check(i)) f=0;
                        }
                        if(f==1) ans++;
                    }
                }
            }
        }
    }
    printf("%lld", ans);

    return 0;
}
