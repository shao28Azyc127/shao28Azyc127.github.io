#include <bits/stdc++.h>

using namespace std;
int ans=0;
bool judge(string s){

    while(1){
        if(s.empty())return 1;
        bool fid=0;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                string news="";
                for(int j=0;j<s.length();j++){
                    if(j==i-1||j==i)continue;
                    news+=s[j];
                }
                s=news;
                fid=1;
                break;
            }
        }
        if(fid==0)return 0;
    }
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    string s;
    cin>>s;
    //solve(1,n,'#','#');
    for(int l=0;l<n;l++){
        for(int r=l+1;r<n;r++){
            string tmp="";
            for(int i=l;i<=r;i++){
                tmp+=s[i];

            }if(judge(tmp)){
                    ans++;
                    //<<tmp<<endl;
                }
        }
    }cout<<ans;
    return 0;
}
