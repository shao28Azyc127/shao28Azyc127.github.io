#include<bits/stdc++.h>
using namespace std;
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+(c-'0');
    x*=f;
}
const int N=100+10;
int n,m,cntst,now;
struct D{
    string stname,name;
    int vis;
}d[2000000];
struct STC{
    string name;
    int typ[N],l,siz,cnt;
    string nam[N];
}stc[N];
struct ST{
    string name;
    int type,pos[N],start;
}st[N];
map<string,int> a,stcid,stid;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    read(n);
    a["byte"]=1;
    a["short"]=2;
    a["int"]=4;
    a["long"]=8;
    for(int i=1;i<=n;++i){
        int op,k;
        read(op);
        if(op==1){
            m++;
            cin>>stc[m].name;read(k);
            stcid[stc[m].name]=m;
            stc[m].cnt=k;
            for(int j=1;j<=k;++j){
                string type,nam;
                cin>>type;cin>>nam;
                stc[m].typ[j]=a[type];
                stc[m].nam[j]=nam;
                stc[m].l=max(stc[m].l,a[type]);
            }

            stc[m].siz=stc[m].l*k;
            printf("%d %d\n",stc[m].siz,stc[m].l);
        }
        if(op==2){
            string strname;
            cin>>strname;
            cntst++;
            st[cntst].type=stcid[strname];
            cin>>st[cntst].name;
            stid[st[cntst].name]=cntst;
            int L=stc[st[cntst].type].l;
            for(int j=1;j<=stc[st[cntst].type].cnt;++j){
                for(int k=now;k<=now+(a[stc[st[cntst].type].nam[j]]);++k){
                    d[k].stname=st[cntst].name;
                    d[k].name=stc[st[cntst].type].nam[j];
                    d[k].vis=1;
                }
                st[cntst].pos[j]=now;
                now+=L;
            }
        }
        if(op==3){
            string p;cin>>p;
            string name,nam;int j=0;
            for(j;j<p.size();++j){
                if(p[j]=='.'){j++;break;}
                else name+=p[j];
            }
            for(j;j<p.size();++j){
                nam+=p[j];
            }
            int tmp=st[stid[name]].type;
            for(int j=1;j<=stc[tmp].cnt;++j){
                if(stc[tmp].nam[j]==nam){printf("%d\n",st[stid[name]].pos[j]);break;}
            }
        }
        if(op==4){
            int p;scanf("%d",&p);
            if(p>now) printf("ERR\n");
            else if(!d[p].vis) printf("ERR\n");
            else cout<<d[p].stname<<'.'<<d[p].name<<endl;
        }
    }
    return 0;
}
