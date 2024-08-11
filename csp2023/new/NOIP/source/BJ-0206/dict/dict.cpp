#include<bits/stdc++.h>
using namespace std;
const int N=3003;
string s[N],str;
int n,m;
int tr[N*N][26],idx;
void ins(int id){
    int p=0;
    int len=s[id].size();
    for(int i=0;i<len;i++){
        int u=s[id][i]-'a';
        if(!tr[p][u]) tr[p][u]=++idx;
        p=tr[p][u];
    }
}
bool Qry(){
    int p=0;
    int len=str.size();
    for(int i=0;i<len;i++){
        int u=str[i]-'a';
        for(int j=0;j<u;j++){
            if(tr[p][j]) return 0;
        }
        if(tr[p][u])p=tr[p][u];
        else return 1;
    }
    return 1;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        sort(s[i].begin(),s[i].end());
        reverse(s[i].begin(),s[i].end());
        ins(i);
    }
    for(int i=1;i<=n;i++){
        str=s[i];
        reverse(str.begin(),str.end());
        cout<<Qry();
    }
    return 0;
}
