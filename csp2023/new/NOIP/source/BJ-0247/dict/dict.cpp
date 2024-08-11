#include<bits/stdc++.h>
using namespace std;
char s[3001][3001],sp[3001][3001];
int n,m;
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        for(int j=0;j<=m;j++)
            sp[i][j]=s[i][j];
        sort(sp[i],sp[i]+m);
        //cout<<sp[i]<<"\n";
    }
    for(int i=1;i<=n;i++){
        bool flag=1;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            //cout<<sp[i]<<" "<<s[j]<<":("<<strcmp(sp[i],s[j])<<")\n";
            if(strcmp(sp[i],s[j])>=1){
                flag=0;
                break;
            }
        }
        if(flag==0){
            cout<<0;
        }else{
            cout<<1;
        }
    }
    cout<<"\n";
    return 0;
}