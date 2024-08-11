#include <bits/stdc++.h>
using namespace std;

const int N=2e6+5;

int n;

long long ans;

char s[N];

vector<int> G[50];

int main() {
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    scanf("%s",s+1);
    if(n>50) {
        int cnt=1;
        for(int i=1;i<=n;i++) {
            if(s[i]==s[i-1]) cnt++;
            else {
                if(cnt%2==0) ans+=cnt*cnt/4;
                else ans+=(cnt+1)*(cnt-1)/4;
                cnt==1;
            }
        }
        //cout<<cnt<<endl;
        if(cnt!=1) {
            if(cnt%2==0) ans+=cnt*cnt/4;
            else ans+=(cnt+1)*(cnt-1)/4;
        }
        cout<<ans<<endl;
        return 0;
    }
    for(int r=2;r<=n;r++) {
        if(s[r]==s[r-1]) {
            G[r].push_back(r-1);
            if(G[r-2].size()) {
                for(int i=0;i<G[r-2].size();i++) {
                    int l=G[r-2][i];
                    G[r].push_back(l);
                    //cout<<l<<" "<<r<<endl;
                }
            }
            //cout<<r-1<<" "<<r<<endl;
        }
        if(G[r-1].size()) {
            for(int i=0;i<G[r-1].size();i++) {
                int l=G[r-1][i];
                if(s[l-1]==s[r]) {
                    G[r].push_back(l-1);
                    //cout<<l-1<<" "<<r<<endl;
                    if(G[l-2].size()) {
                        for(int j=0;j<G[l-2].size();j++) {
                            if(s[G[l-2][j]]!=s[r]) G[r].push_back(G[l-2][j]);//cout<<G[l-2][j]<<" "<<r<<endl;
                        }
                    }
                }
            }
        }
        ans+=G[r].size();
    }
    cout<<ans<<endl;
    return 0;
}
//meow