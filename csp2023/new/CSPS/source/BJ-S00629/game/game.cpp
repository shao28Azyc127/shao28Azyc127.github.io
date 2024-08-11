#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
string s;
struct jg{
    int r,l;
}a[10001];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    s=" "+s;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j+=2){
            for(int k=1;k<=n;k++){
                a[k].r=k-1;
                a[k].l=k+1;
            }
            int ans=0;
            for(int k=1;k*2<=j-i+1;k++){
                for(int g=i;g<=j;g++){
                    if(s[g]==s[a[g].l]&&a[g].l!=-1&&a[a[g].l].l!=-1&&a[g].l<=j){
                        a[a[g].r].l=a[a[g].l].l;
                        a[a[a[g].l].l].r=a[g].r;
                        a[g].l=-1;
                        a[a[g].l].l=-1;
                        ans++;
                    }
                }
            }
            if(ans*2==j-i+1){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
