# include <bits/stdc++.h>
using namespace std;
map <int,bool> p;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    cin>>n;
    long long t;
    long long ans = 0;
    long long b = 0;
    while(b<n){
        ans++;
        int l = 2;
        for(int i=1;i<=n;i++){
            if(p[i]!=1){
                l++;
            }
            if(l==3){
                l = 0;
                p[i] = 1;
                b++;
                if(i==n) t = ans;
            }
        }
    }
    cout<<ans<<" "<<t;
    return 0;
}
