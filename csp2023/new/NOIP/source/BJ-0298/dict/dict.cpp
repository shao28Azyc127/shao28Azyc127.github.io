#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cmath>
#define int long long
#define ull unsigned long long
using namespace std;
int n,m;
string s[3005];
int buck[3005][30],t[3005][30];
bool cmp(char x,char y){
    return x>y;
}
signed main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(register int i=1;i<=n;++i){
        cin>>s[i];
        for(int j=0;j<m;++j)
            buck[i][s[i][j]-'a'+1]++;
    }
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        bool flag=false;
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            int k1=1;
            while(buck[i][k1]==0&&k1<=26)k1++;
            int k2=26;
            while(buck[j][k2]==0&&k2>=0)k2--;
         //   cout<<i<<' '<<k1<<' '<<j<<' '<<k2<<endl;
            if(k1>=k2){
                flag=true;
                break;
            }
        }
        if(flag)cout<<0;
        else cout<<1;
    }
    cout<<endl;
    return 0;
}
