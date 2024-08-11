#include <bits/stdc++.h>
using namespace std;
string s[3005],s1[3005];
int n,m;
void init(){
    for (int i=1;i<=n;i++){
        s1[i]=s[i];
    }
    return;
}
void s_sort(bool rever,int o){
    for (int i=0;i<=m-1;i++){
        for (int j=i+1;j<=m-1;j++){
            if (rever&&s1[o][i]<s1[o][j]){
                char c=s1[o][i];
                s1[o][i]=s1[o][j];
                s1[o][j]=c;
            }
            if (!rever&&s1[o][i]>s1[o][j]){
                char c=s1[o][i];
                s1[o][i]=s1[o][j];
                s1[o][j]=c;
            }
        }
    }
    return;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>s[i];
    }
    for (int q=1;q<=n;q++){
            init();
        for (int i=1;i<=n;i++){
            s_sort(i!=q,i);
        }
        string ns=s1[q];
        int flag=1;
        for (int i=1;i<=n;i++){
            if (i==q) continue;
            if (s1[i]<ns){
                flag=0;
                break;
            }
        }
        cout<<flag;
    }
    return 0;
}
