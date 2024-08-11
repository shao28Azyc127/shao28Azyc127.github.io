#include<bits/stdc++.h>
using namespace std;
int n,m,a[3010][30],b[3010][30];
string s;
bool yes(int x){
    for(int j=1;j<=26;j++){
        if(a[x][j]){
            for(int i=1;i<=n;i++){
                if(i==x)continue;
                if(b[i][j+1]==0)return false;
            }
            break;
        }
    }
    return true;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=0;j<m;j++)a[i][s[j]-'a'+1]++;
        for(int j=26;j>=1;j--)b[i][j]=b[i][j+1]+a[i][j];
    }
    for(int i=1;i<=n;i++){
        if(yes(i))cout<<1;
        else cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
