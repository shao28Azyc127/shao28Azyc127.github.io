#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;
int n,m,k,s,t,tot,tot1,tot2;
ll now,addr;
string U,V[105];
pair<string,int> p[4];
ll calc(ll x,ll y){ return x%y==0?x:(x/y+1)*y;}
int ok(string S){
    for (int i=0;i<4;++i) if (S==p[i].first) return 1;
    return 0;
}
struct node3{
    string S;
    ll siz,_a;
}C[105];
struct node{
    string S,s1[N],s2[N];
    int k;
    ll s[N],a[N],o[N],siz,_a;
    void init(){
        cin>>S>>k;
        for (int i=1;i<=k;++i){
            cin>>s1[i]>>s2[i];
            for (int j=0;j<=3;++j) if (s1[i]==p[j].first) s[i]=a[i]=p[j].second;
            if (!s[i]) {
                for (int j=0;j<tot;++j)
                    if (C[j].S==s1[i]) s[i]=C[j].siz,a[i]=C[j]._a;
            }
            _a=max(_a,a[i]);
        }
        o[1]=0;
        for (int i=2;i<=k;++i)
            o[i]=calc(o[i-1]+s[i-1],a[i]);
        siz=calc(o[k]+s[k],_a);
        cout<<siz<<' '<<_a<<"\n";
        C[tot].S=S;C[tot].siz=siz;C[tot]._a=_a;
    }
}A[105];
struct node2{
    string S1,S2;
    ll siz,_a,b;
    void init(ll x,ll y){
        cin>>S1>>S2;
        for (int i=0;i<=3;++i)
            if (S1==p[i].first) siz=_a=p[i].second;
        if (siz==0)
            for (int i=1;i<=tot;++i) if (A[i].S==S1) siz=A[i].siz,_a=A[i]._a;
        if (tot1==0) b=0;
        else b=calc(x+y,_a);
        cout<<b<<"\n";
    }
}B[105];
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    p[0]={"byte",1};p[1]={"short",2};p[2]={"int",4};p[3]={"long",8};
    cin>>n;int opt,o;
    for (int i=1;i<=n;++i){
        cin>>opt;
        if (opt==1){
            ++tot;
            A[tot].init();
        }
        else if (opt==2){
            ++tot1;
            B[tot1].init(B[tot1-1].b,B[tot1-1].siz);
        }
        else if (opt==3){
            cin>>U;
            m=U.size();
            V[tot2=1]="";
            for (int j=0;j<m;++j)
                if (U[j]!='.') V[tot2]+=U[j];
                else V[++tot2]="";
            for (int j=1;j<=tot1;++j)
                if (B[j].S2==V[1]) now=B[j].b,U=B[j].S1;
            for (int j=2;j<=tot2;++j){
            //    cout<<now<<' '<<U<<"\n";
                for (o=1;o<=tot;++o)
                    if (U==A[o].S) break;
                for (int _o=1;_o<=A[o].k;++_o)
                    if (A[o].s2[_o]==V[j]){
                        now+=A[o].o[_o];
                        U=A[o].s1[_o];
                    }
            }
            cout<<now<<"\n";
        }
        else {
            cin>>addr;U="";string V;
            for (int j=1;j<=tot1;++j)
                if (B[j].b<=addr && B[j].b+B[j].siz-1>=addr) {
                    V=B[j].S1;
                    U=B[j].S2;
                    addr-=B[j].b;
                    break;
                }
            int bo;
            while (!ok(V)){
                for (o=1;o<=tot;++o)
                    if (A[o].S==V) break;
                bo=0;
                for (int _o=1;_o<=A[o].k;++_o)
                    if (A[o].o[_o]<=addr && A[o].o[_o]+A[o].s[_o]-1>=addr){
                        V=A[o].s1[_o];
                        U+="."+A[o].s2[_o];
                        addr-=A[o].o[_o];
                        bo=1;
                        break;
                    }
                if (!bo) break;
            }
            if (bo) cout<<U<<"\n";
            else cout<<"ERR\n";
        }

    }
}
