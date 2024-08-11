//dthkxy ak ioi
#include<bits/stdc++.h>
#define int long long
using namespace std;

map <string,int> mp;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    int n; cin>>n;
    int tmp; tmp=n;

    int ans; ans=0;
    while(n--){
        string s;
        string t;

        for(int i=0;i<5;i++){
            char c; cin>>c;
            s+=c;
        }

        t=s;
        for(int i=0;i<5;i++){
            for(int j=1;j<=9;j++){
                char x; x=(s[i]-'0'+j)%10+'0';
                s[i]=x;
                //cout<<s<<endl;

                mp[s]++;

                if(mp[s]==tmp){
                    ans++;
                }

                s=t;
            }
        }

        for(int i=0;i<4;i++){
            for(int j=1;j<=9;j++){
                char x; x=(s[i]-'0'+j)%10+'0';
                s[i]=x;
                x=(s[i+1]-'0'+j)%10+'0';
                s[i+1]=x;
                //cout<<s<<endl;

                mp[s]++;

                if(mp[s]==tmp){
                    ans++;
                }

                s=t;
            }
        }
    }

    cout<<ans;
    return 0;
}
