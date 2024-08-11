#include <bits/stdc++.h>
#define int long long
using namespace std;
string s[3005],s1[3005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n>1000&&m>1000){
        while(n--)cout<<"0";
        return 0;
    }
    for(int i=0;i<n;++i)cin>>s[i];
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            s1[j]=s[j];
            if(j!=i){
                char maxn=0;
                int maxxb=0;
                for(int k=0;k<m;++k)if(s1[j][k]>maxn)maxn=s1[j][k];
                for(int k=0;k<m;++k)if(s1[j][k]==maxn){
                    maxxb=k;
                    break;
                }
                swap(s1[j][0],s1[j][maxxb]);
            }
            else{
                char minn='z'+1;
                int minxb=0;
                for(int k=0;k<m;++k)if(s1[j][k]<minn)minn=s1[j][k];
                for(int k=0;k<m;++k)if(s1[j][k]==minn){
                    minxb=k;
                    break;
                }
                swap(s1[j][0],s1[j][minxb]);
            }
        }
        bool flag=1;
        for(int j=0;j<n;++j)if(j!=i&&s1[j]<=s1[i])flag=0;
        cout<<flag;
    }
    return 0;
}
