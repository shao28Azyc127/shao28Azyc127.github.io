#include<bits/stdc++.h>
using namespace std;
int n;
string s;
bool check(int l,int r){
    string s2=s.substr(l,r-l+1);
    while(!s2.empty()){
        int si=s2.size();
        bool pd=0;
        for(int i=0;i<si-1;i++){
            if(s2[i]==s2[i+1]){
                s2.erase(s2.begin()+i,s2.begin()+i+2);
                pd=1;
                break;
            }
        }
        if(!pd)return false;
    }
    return true;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>s;
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(check(i,j))ans++;
        }
    }
    cout<<ans;
    return 0;
}
