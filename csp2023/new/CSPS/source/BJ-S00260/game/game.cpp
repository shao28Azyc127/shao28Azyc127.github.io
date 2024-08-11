#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> a[9000],b[9000];//a[i] shows the amount of strings which starts from a;b[i] shows the amount of strings which's length is i
char c[9000];
signed main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>c[i];
    }
    for (int i=1;i<n;i++){
        if (c[i]==c[i+1]){
            a[i].push_back(2);
            b[2].push_back(i);
        }
    }
    for (int i=2;i<=n;i+=2){
        for (int j=0;j<b[i].size();j++){
            int k=b[i][j];
            if (c[k-1]==c[k+i]) {
                b[i+2].push_back(k-1);
                a[k-1].push_back(i+2);
            }
            for (int l=0;l<a[k+i].size();l++){
                int r=a[k+i][l];
                a[k].push_back(i+r);
                b[i+r].push_back(k);
            }
        }
    }
    int ans=0;
    for (int i=2;i<=n;i+=2) ans+=b[i].size();
    cout<<ans;
}
