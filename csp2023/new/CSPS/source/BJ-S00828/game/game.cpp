#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long ans;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            ans++;
        }
    }
    for(int i=1;i<n-2;i++){
        if(s[i]==s[i+1]&&s[i-1]==s[i+2]) ans++;
        else if(s[i]==s[i-1]&&s[i+1]==s[i+2]) ans++;
    }
    for(int i=2;i<n-3;i++){
        if(s[i-2]==s[i-1]){
            if(s[i]==s[i+1]&&s[i+2]==s[i+3]) ans++;
            else if(s[i]==s[i+3]&&s[i+1]==s[i+2]) ans++;
        }else if(s[i]==s[i+1]&&s[i-1]==s[i+2]&&s[i-2]==s[i+3]) ans++;
        else if(s[i]==s[i-1]&&s[i-2]==s[i+1]&&s[i+2]==s[i+3]) ans++;
    }
    for(int i=3;i<n-4;i++){
        if(s[i-3]==s[i-2]){
            if(s[i-2+1]==s[i-1+1]){
            if(s[i+1]==s[i+1+1]&&s[i+1+2]==s[i+1+3]) ans++;
            else if(s[i+1]==s[i+1+3]&&s[i+1+1]==s[i+1+2]) ans++;
        }else if(s[i+1]==s[i+1+1]&&s[i+1-1]==s[i+1+2]&&s[i+1-2]==s[i+1+3]) ans++;
        else if(s[i+1]==s[i+1-1]&&s[i+1-2]==s[i+1+1]&&s[i+1+2]==s[i+1+3]) ans++;
        }else if(s[i]==s[i-3]&&s[i-2]==s[i-1]){
            if(s[i+2]==s[i+2+1]&&s[i-1+2]==s[i+2+2]) ans++;
        else if(s[i+2]==s[i+2-1]&&s[i+2+1]==s[i+2+2]) ans++;
        }
    }
    cout<<ans;
    return 0;
}
