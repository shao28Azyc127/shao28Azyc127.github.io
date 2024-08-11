#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3005;

ll rd() {
    ll s=0, f=1;
    char ch=getchar();
    for(; !isdigit(ch); ch=getchar())
        if(ch=='-') f=-1;
    for(; isdigit(ch); ch=getchar())
        s=(s<<1)+(s<<3)+(ch^48);
    return s*f;
}

ll n, m, ans[N];
string str[N], mx[N], mn[N];
char ch[N];
int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    if(n==1) {
        printf("1");
        return 0;
    }
    for(ll i=1; i<=n; i++) {
        scanf("%s", ch);
        str[i]=ch;
        str[i]='0'+str[i];
       // for(ll j=1; j<=m; j++) cout <<j << " " <<str[i][j]<<endl;
       mx[i]=str[i];
       mn[i]=str[i];
     /*   for(ll j=1; j<=m; j++) {
            for(ll k=1; k<=j; k++) {
                if(j!=k) {
                    swap(str[i][j], str[i][k]);
                    mx[i]=max(mx[i], str[i]);
                    mn[i]=min(mn[i], str[i]);
                    swap(str[i][j], str[i][k]);
                }
            }
        }*/

        char mnc=str[i][m];
        ll p=m;
        for(ll j=m; j>=1; j--) {
            if(str[i][j]<mnc) {
                mnc=str[i][j];
                p=j;
                continue;
            }
            if(str[i][j]==mnc) {
                continue;
            }
            if(str[i][j]>=mnc) {
                swap(str[i][j], str[i][p]);
                mn[i]=min(mn[i], str[i]);
                swap(str[i][j], str[i][p]);
            }
        }

        char mxc=str[i][m];
        p=m;
        for(ll j=m; j>=1; j--) {
            if(str[i][j]>mxc) {
                mxc=str[i][j];
                p=j;
                continue;
            }
            if(str[i][j]==mxc) {
                continue;
            }
            if(str[i][j]<=mxc) {
                swap(str[i][j], str[i][p]);
                mx[i]=max(mx[i], str[i]);
                swap(str[i][j], str[i][p]);
            }
        }

 //       cout <<str[i]<<endl;
   //     cout << mn[i]<<endl;
     //   cout << mx[i]<<endl;

        //char mxc=str[1];
      //  p=1;
    //    for(ll)


   //    cout<<str[i]<<endl;
    //    cout<<mx[i]<<endl;
     //   cout<<mn[i]<<endl<<endl;
    }

    for(ll i=1; i<=n; i++) {
        ll f=1;
        for(ll j=1; j<=n; j++) {
            if(i==j) continue;
            if(mn[i]>mx[j]) {
                f=0;
                break;
            }
        }
        ans[i]=f;
    }

    for(ll i=1; i<=n; i++)
        if(ans[i]==1) putchar('1');
        else putchar('0');

    return 0;
}
