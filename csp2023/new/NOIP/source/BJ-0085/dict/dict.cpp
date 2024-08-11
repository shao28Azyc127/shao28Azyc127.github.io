#include<bits/stdc++.h>
using namespace std;
string w[3005],s1[3005],s2[3005];
int n,m;
bool cmp(char x,char y){
    return x>y;
}
int main(){
    #ifndef JZQ
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        s1[i]=s2[i]=w[i];
        sort(s1[i].begin(),s1[i].end());
        sort(s2[i].begin(),s2[i].end(),cmp);
        // cout<<s1[i]<<" "<<s2[i]<<endl;
    }
    for(int i=1;i<=n;i++){
        bool flag=true;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            flag=flag&&s1[i]<s2[j];
        }
        cout<<flag;
    }
    return 0;
}