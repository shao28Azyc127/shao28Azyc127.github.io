#include<bits/stdc++.h>
using namespace std;
int n,m;
string a;
struct node{
    int maxtmp,maxnum,mintmp,minnum;
}data[3100];
void solve(int x){
    for(int i=1;i<=n;i++){
        if(i==x) continue;
        if(data[x].mintmp>data[i].maxtmp){
            cout << 0;
            return ;
        }
        else if(data[x].mintmp==data[i].maxtmp){
            if(data[x].minnum>=data[i].maxnum){
                cout << 0;
                return ;
            }
        }
    }
    cout << 1;
    return ;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        data[i].mintmp=999999;
        cin >> a;
        for(int j=0;j<m;j++){
            int ch=a[j]-'a'+1;
            if(ch==data[i].maxtmp) data[i].maxnum++;
            if(ch==data[i].mintmp) data[i].minnum++;
            if(ch>data[i].maxtmp){
                data[i].maxtmp=ch;
                data[i].maxnum=1;
            }
            if(ch<data[i].mintmp){
                data[i].mintmp=ch;
                data[i].minnum=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        solve(i);
    }
    return 0;
}
