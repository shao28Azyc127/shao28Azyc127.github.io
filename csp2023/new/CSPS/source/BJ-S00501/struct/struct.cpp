#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Jr{
    string t,n;
};
struct Node{
    Jr x[110];int siz,k;
    inline bool operator<(const Node &p){
        return siz<p.siz;
    }
};
struct Rxs{
    int pos,siz;string s;
    inline bool operator<(const Rxs &p){
        return pos<p.pos;
    }
};
int n,last;
map<string,Node> m;
map<string,int> q;
map<string,Rxs> w;
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(0);
    q["byte"]=1;q["short"]=2;q["int"]=4;q["long"]=8;
    cin>>n;
    for(int i=1,op,k;i<=n;i++){
        string s;cin>>op;
        if(op==1){
            cin>>s>>k;m[s].siz=k;int a=0;
            for(int j=1;j<=k;j++){
                cin>>m[s].x[j].t>>m[s].x[j].n;
                string p=m[s].x[j].t;
                m[s].k=max(m[s].k,q[p]);
            }
            cout<<m[s].siz*m[s].k<<" "<<m[s].k<<'\n';
            
        }
        if(op==2){
            string p;
            cin>>s>>p;w[p].pos=last;w[p].s=s;
            if(q[s]>0) w[p].siz=q[s];
            else w[p].siz=m[s].siz*m[s].k;
            cout<<last<<'\n';last+=w[p].siz;
        }
        if(op==3){
            cin>>s;int len=s.size(),flag=0,p=0;
            for(int j=0;j<len;j++) 
                if(s[j]=='.'){flag=1;p=j;break;}
            if(flag==0) cout<<w[s].pos<<'\n';
            else{
                string x=s.substr(p+1,len-p-1),y=s.substr(0,p);
                for(int j=1;j<=m[w[y].s].siz;j++)
                    if(m[w[y].s].x[j].n==x){cout<<w[y].pos+(j-1)*m[w[y].s].k<<'\n';break;}
            } 
        }
        if(op==4){
            cin>>k;int flag=0;
            for(auto j=w.begin();j!=w.end();j++) {
                string p=j->first;
                if(q[p]>0) {if(w[p].pos<=k&&k<=w[p].pos+w[p].siz) {cout<<p<<'\n';flag=1;break;}}  
                else{
                    string x=w[p].s;int sum=0;
                    for(int j=1;j<=m[x].siz;j++){
                        int d1=w[p].pos+(j-1)*m[x].k,d2=w[p].pos+(j-1)*m[x].k+q[m[x].x[j].t]-1;
                        //cout<<d1<<" "<<d2<<"\n";
                        if(d1<=k&&k<=d2) {cout<<p<<"."<<m[x].x[j].n<<'\n';flag=1;break;}
                    }
                    if(flag) break;  
                }
            }
            if(flag==0) cout<<"ERR\n";
        }
    }
    return 0;
}