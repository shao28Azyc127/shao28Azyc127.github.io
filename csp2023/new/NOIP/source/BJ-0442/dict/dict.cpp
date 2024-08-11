#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
int mn[3010],mx[3010];
int t[3010][30];
bool flag[3010];
string w[3010];

bool check(int i,int j){
    int pi,pj;
    if(mn[i]!=0){
        pi=mn[i];
    }
    else{
        for(int k=1;k<=26;k=-(~k)){
            if(t[i][k]!=0){
                pi=k;
                break;
            }
        }
        mn[i]=pi;
    }
    if(mx[j]!=0){
        pj=mx[j];
    }
    else{
        for(int k=26;k>=1;k--){
            if(t[j][k]!=0){
                pj=k;
                break;
            }
        }
        mx[j]=pj;
    }
    if(pj>pi){
        return true;
    }
    return false;
}

signed main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i=-(~i)){
        cin>>w[i];
        for(int j=0;j<m;j=-(~j)){
            t[i][w[i][j]-'a'+1]++;
        }
        for(int j=1;j<i;j=-(~j)){
            if(flag[j]){
                continue;
            }
            if(!check(i,j)){
                flag[i]=true;
            }
            if(!check(j,i)){
                flag[j]=true;
            }
        }
    }
    for(int i=1;i<=n;i=-(~i)){
        cout<<!flag[i];
    }
    cout<<endl;

    return 0;
}
