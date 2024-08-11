#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,op,now,cnt;
string a,b;
map<string,int> mp;
int pos[1005];
string st[1005];
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    while(n--){
        scanf("%lld",&op);
        if(op==2){
            cin>>a>>b;
            mp[b]=++cnt;
            pos[cnt]=now;
            st[cnt]=b;
            switch(a[0]){
                case 'b': now+=1;break;
                case 's': now+=2;break;
                case 'i': now+=4;break;
                case 'l': now+=8;break;
            }
        }
        else if(op==3){
            cin>>a;
            printf("%lld\n",pos[mp[a]]);
        }
        else if(op==4){
            int x,i;
            scanf("%lld",&x);
            if(now<=x){puts("ERR");continue;}
            i=upper_bound(pos+1,pos+cnt+1,x)-pos-1;
            cout<<st[i]<<endl;
        }
    }
    return 0;
}
