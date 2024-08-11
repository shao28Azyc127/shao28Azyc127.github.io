#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<string,ll>mp,rule;//mp:size rule:adress
map<ll,string>adr;
void init(){
    mp["byte"]=1;
    mp["short"]=2;
    mp["int"]=4;
    mp["long"]=8;
}
ll t;
ll opt,x,n;
string s1,s;
ll ans=0;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&opt);
        if(opt==2){
        cin>>s>>s1;//need real space
        printf("%lld\n",ans);
        mp[s1]=ans;
        for(int i=ans;i<=ans+(mp[s]-1);i++) adr[i]=s1;
        ans+=mp[s];
    }
    else if(opt==3){
        cin>>s;
        printf("%lld\n",mp[s]);
    }else if (opt==4){
        scanf("%lld",&x);
        s1=adr[x];
        if(s1.size()!=0) cout<<adr[x]<<endl;
        else cout<<"ERR"<<endl;
    }
    }
    return 0;
}
