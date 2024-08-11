#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long ansf;
long long ans;
long long cnt[30000];
long long dp[2000010];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    /*for(int i=1;i<=1000;i++){
        ans=0;
        for(int j=0;j<s.size();j++){
            if(s[j]==s[j+1]){
                ans++;
                s.erase(j,2);
            }

        }
        if(ans==0)break;
        cout<<ans<<endl;
        ansf+=ans;
    }
    if(s.size()==0){
        ansf++;
    }*/
    for(int i=0;i<s.size();i++){
        cnt[s[i]-'0'-48]++;
    }
    /*for(int i=1;i<=26;i++){
        cout<<cnt[i]<<endl;
    }*/
    for(int i=2;i<=n;i+=2){
        for(int j=0;j<=n-i;j++){
            string s1=s.substr(j,i);
            //cout<<s1<<endl;
            int ans1=0;
            for(int p=1;p<=20;p++){
                ans1=0;
                for(int q=0;q<s1.size();q++){
                    if(s1[q]==s1[q+1]){
                        ans1++;
                        s1.erase(q,2);
                    }
                }

            }
            if(s1.size()==0)ans++;
        }
    }
    cout<<ans;
    return 0;
}
