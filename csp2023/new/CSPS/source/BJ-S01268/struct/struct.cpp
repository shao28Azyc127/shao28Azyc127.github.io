#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=1000005;
ll n;

map<ll, ll> ad[maxn];

ll cnt=0, pos=0;
struct node{
    ll s, t;
};
node stru[maxn];

map<string, ll> K;
string M[maxn];
ll f[maxn];

string str, k;
void vinit(){
    cin>>str>>k;
    if(str=="byte") {
        K[k]=++cnt;
        M[cnt]=k;
        f[cnt]=1;
        stru[cnt].s=pos;
        stru[cnt].t=pos;
        ad[pos]=cnt;
        cout<<pos<<endl;
        pos+=1;
    } else if(str=="short") {
        K[k]=++cnt;
        M[cnt]=k;
        f[cnt]=2;
        if(pos%2!=0) pos=pos-(pos%2)+2;
        stru[cnt].s=pos;
        stru[cnt].t=pos+1;
        ad[pos]=ad[pos+1]=cnt;
        cout<<pos<<endl;
        pos+=2;
    } else if(str=="int") {
        K[k]=++cnt;
        M[cnt]=k;
        f[cnt]=3;
        if(pos%4!=0) pos=pos-(pos%4)+4;
        stru[cnt].s=pos;
        stru[cnt].t=pos+3;
        ad[pos]=ad[pos+1]=ad[pos+2]=ad[pos+3]=cnt;
        cout<<pos<<endl;
        pos+=4;
    } else {
        K[k]=++cnt;
        M[cnt]=k;
        f[cnt]=4;
        if(pos%8!=0) pos=pos-(pos%8)+8;
        stru[cnt].s=pos;
        stru[cnt].t=pos+7;
        ad[pos]=ad[pos+1]=ad[pos+2]=ad[pos+3]=ad[pos+4]=ad[pos+5]=ad[pos+6]=ad[pos+7]=cnt;

        cout<<pos<<endl;
        pos+=8;
    }
}

string g;
void goe() {
    cin>>g;
    ll p=K[g];
    cout<<stru[p].s<<endl;
}

ll a;
void goa() {
    cin>>a;
    ll p=ad[a];
    string m=M[p];
    if(M[p]=="") cout<<"ERR"<<endl;
    else cout<<m<<endl;
}

ll x;
void work(){
    scanf("%lld", &x);
    if(x==2) vinit();
    else if(x==3) goe();
    else if(x==4) goa();
}

int main() {

    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    scanf("%lld", &n);
    while(n--) work();

    return 0;
}
