#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<iostream>
using namespace std;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
const int maxn=105;
int T,ns;
struct node{
    string name;
    int dq,num;
    int m_type[maxn];
    long long st[maxn],ed[maxn],sz;
    string m_name[maxn];
    map<string,int> dy;
}yl[maxn+5];
void make_dy(node &g){
    for(int i=1;i<=g.num;++i){
        g.dy[g.m_name[i]]=i;
    }
}
int ft(const string& x){
    for(int i=1;i<=ns;++i)if(x==yl[i].name)return i;
}
int n,tp[maxn];
long long St[maxn],Ed[maxn];
string Name[maxn];
int find(const string& x){
    for(int i=1;i<=n;++i)if(x==Name[i])return i;
}
int cnt;
string tmp,tmp_[maxn];
void split(){
    tmp.push_back('.');
    cnt=0;
    for(int x=0,lt=0;x<tmp.size();++x)if(tmp[x]=='.'){
        tmp_[cnt].clear();
        for(int i=lt;i<x;++i)tmp_[cnt].push_back(tmp[i]);
        ++cnt;
        lt=x+1;
    }
}
long long fx(long long x,int y){
    return (x+y-1)/y*y;
}
long long get_add(int now,int x){
    if(x>=cnt)return 0;
    int cy=yl[now].dy[tmp_[x]];
    return yl[now].st[cy]+get_add(yl[now].m_type[cy],x+1);
}
int find_add(int now,long long x){
    if(yl[now].num==0)return 1;
    int cy=upper_bound(yl[now].st+1,yl[now].st+yl[now].num+1,x)-yl[now].st-1;
    if(cy==0||x>yl[now].ed[cy])return 0;
    tmp.push_back('.');
    tmp=tmp+yl[now].m_name[cy];
    return find_add(yl[now].m_type[cy],x-yl[now].st[cy]);
}
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    yl[++ns].name="byte";
    yl[ns].dq=yl[ns].sz=1;
    yl[++ns].name="short";
    yl[ns].dq=yl[ns].sz=2;
    yl[++ns].name="int";
    yl[ns].dq=yl[ns].sz=4;
    yl[++ns].name="long";
    yl[ns].dq=yl[ns].sz=8;
    Ed[0]=-1;
    cin>>T;
    while(T--){
        int op;cin>>op;
        if(op==1){
            ++ns;
            cin>>yl[ns].name>>yl[ns].num;
            for(int i=1;i<=yl[ns].num;++i){
                cin>>tmp>>yl[ns].m_name[i];
                yl[ns].m_type[i]=ft(tmp);
                yl[ns].st[i]=fx(yl[ns].sz,yl[yl[ns].m_type[i]].dq);
                yl[ns].ed[i]=yl[ns].st[i]+yl[yl[ns].m_type[i]].sz-1;
                yl[ns].sz=yl[ns].ed[i]+1;
                yl[ns].dq=max(yl[ns].dq,yl[yl[ns].m_type[i]].dq);
            }
            yl[ns].sz=fx(yl[ns].sz,yl[ns].dq);
            make_dy(yl[ns]);
            cout<<yl[ns].sz<<' '<<yl[ns].dq<<'\n';
        }
        else if(op==2){
            ++n;
            cin>>tmp>>Name[n];
            tp[n]=ft(tmp);
            St[n]=fx(Ed[n-1]+1,yl[tp[n]].dq);
            Ed[n]=St[n]+yl[tp[n]].sz-1;
            cout<<St[n]<<'\n';
        }
        else if(op==3){
            cin>>tmp;
            split();
            int ny=find(tmp_[0]);
            cout<<St[ny]+get_add(tp[ny],1)<<'\n';
        }
        else if(op==4){
            long long x;cin>>x;
            int ne=0;
            for(int i=1;i<=n;++i){
                if(St[i]<=x&&x<=Ed[i]){
                    ne=i;
                    break;
                }
            }
            if(ne){
                tmp=Name[ne];
                if(find_add(tp[ne],x-St[ne]))cout<<tmp<<'\n';
                else cout<<"ERR\n";
            }
            else cout<<"ERR\n";
        }
    }
    return 0;
}