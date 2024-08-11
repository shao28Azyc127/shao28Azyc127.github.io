#include<cstdio>
#include<string>
#include<map>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN=110,MAXM=1e5+10;
string str,st[MAXN],s[MAXN][MAXN],typ,ans[MAXM],st1,st2;
map<string,int> mp,mps[MAXN],mp2;
int a[MAXN][MAXN],o[MAXN][MAXN],num[MAXN],ma[MAXN],sis[MAXN],siz[MAXN],b[MAXN],idx[MAXN];
ll read(){
    ll num=0,sign=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')num=num*10+ch-'0',ch=getchar();
    return num*sign;
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int Q=read(),n=0,m=0;
    while(Q--){
        int op=read();
        if(op==1){
            cin>>str;int k=read();
            mp[str]=(++n);st[n]=str;num[n]=k;
            for(int i=1;i<=k;i++){
                cin>>typ>>s[n][i];mps[n][s[n][i]]=i;
                if(typ=="byte") a[n][i]=1;
                if(typ=="short") a[n][i]=2;
                if(typ=="int") a[n][i]=4;
                if(typ=="long") a[n][i]=8;
                ma[n]=max(ma[n],a[n][i]);
            }
            for(int i=2;i<=k;i++){
                o[n][i]=o[n][i-1]+a[n][i-1];
                while(o[n][i]%a[n][i]) o[n][i]++;
            }
            sis[n]=o[n][k]+a[n][k];
            while(sis[n]%ma[n]) sis[n]++;
            printf("%d %d\n",sis[n],ma[n]);
        }
        if(op==2){
            cin>>typ>>str;mp2[str]=++m;
            b[m]=b[m-1]+siz[m-1];
            if(typ=="byte") {siz[m]=1;ans[b[m]]=str;}
            else if(typ=="short"){siz[m]=2;while(b[m]%2)b[m]++;for(int i=0;i<2;i++)ans[b[m]+i]=str;}
            else if(typ=="int")  {siz[m]=4;while(b[m]%4)b[m]++;for(int i=0;i<4;i++)ans[b[m]+i]=str;}
            else if(typ=="long") {siz[m]=8;while(b[m]%8)b[m]++;for(int i=0;i<8;i++)ans[b[m]+i]=str;}
            else{
                int id=mp[typ];idx[m]=id;
                siz[m]=sis[id];int k=num[id];
                while(b[m]%ma[id]) b[m]++;
                for(int i=1;i<=k;i++)
                    for(int j=0;j<a[id][i];j++) ans[b[m]+o[id][i]+j]=(str+"."+s[n][i]);
            }
            printf("%d\n",b[m]);
        }
        if(op==3){
            cin>>str;
            bool fl=0;
            for(int i=0;i<str.size();i++) if(str[i]=='.') fl=1;
            if(!fl) printf("%d\n",b[mp2[str]]);
            else{
                int i=0;st1="",st2="";
                while(str[i]!='.') st1+=str[i],i++;
                i++;for(;i<str.size();i++) st2+=str[i];
                int id=idx[mp2[st1]],pl=b[mp2[st1]];
                printf("%d\n",pl+o[id][mps[id][st2]]);
            }
        }
        if(op==4){
            ll x=read();
            if(x>100000||ans[x]=="") printf("ERR\n");
            else cout<<ans[x]<<endl;
        }
    }
    return 0;
}