#include <bits/stdc++.h>
#define int long long
using namespace std;
//map<string,int> mp;
map<string,int> mp1;
map<int,string> mp2;
int judgr(string s){
    if(s=="byte") return 1;
    if(s=="short") return 2;
    if(s=="int") return 4;
    if(s=="long") return 8;
    return -1;
}
int n,sum;
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%lld",&n);
    while(n--){
        int op;
        scanf("%lld",&op);
        if(op==1){
            /*string s;,int n;
            cin>>s;
            mp[s]=++cnt;
            scanf("%d",&n);
            for(int i=1;i<=n;i++){

            }*/
        }else if(op==2){
            string s1,s2;
            cin>>s1>>s2;
            mp1[s2]=sum;
            for(int i=sum;i<sum+judgr(s1);i++) mp2[i]=s2;
            sum+=judgr(s1);
        }else if(op==3){
            string s;
            cin>>s;
            printf("%lld\n",mp1[s]);
        }else{
            int x;
            scanf("%lld",&x);
            if(x>=sum) printf("ERR\n");
            else cout<<mp2[x]<<'\n';
        }
    }
    return 0;
}
