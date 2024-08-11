#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
void read(int &number){
    number=0;
    bool fuhao=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')fuhao=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        number*=10;
        number+=ch-'0';
        ch=getchar();
    }
    if(fuhao)number=-number;
    return;
}
void lread(long long &number){
    number=0;
    bool fuhao=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')fuhao=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        number*=10;
        number+=ch-'0';
        ch=getchar();
    }
    if(fuhao)number=-number;
    return;
}
void print(LL number){
    if(number<0){
        putchar('-');
        number=-number;
    }
    if(number>9){
        print(number/10);
    }
    putchar((number%10)^48);
}
LL js(string s){
    LL x=0;
    for(int i=0;i<s.length();i++){
        x*=26;
        x+=s[i]-'a';
    }
    return x;
}
struct node{
    LL sz;
    int dq;
}f[109];
map<LL,int> mp;
vector<LL> q;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    string s,x,y;
    char tt;
    int n,k,a;
    LL res;
    LL b;
    cin>>n;
    mp[js("byte")]=1;
    mp[js("short")]=2;
    mp[js("int")]=3;
    mp[js("long")]=4;
    f[1]={1,1};
    f[2]={2,2};
    f[3]={4,4};
    f[4]={8,8};
    for(int i=1;i<=n;i++){
        cin>>tt;
        cin>>s>>k;
        mp[js(s)]=i+4;
        a=1;
        b=0;
        int ss=0;
        for(int j=1;j<=k;j++){
            cin>>x>>y;
            res=js(x);
            a=max(a,f[mp[res]].dq);
            ss+=f[mp[res]].sz;
            if(b%f[mp[res]].dq==0)b+=f[mp[res]].sz;
            else b=(b/f[mp[res]].dq+1)*f[mp[res]].dq+f[mp[res]].sz;
        }
        if(b%a!=0)b=(b/a+1)*a;
        f[i+4]={b,a};
        print(b);
        putchar(' ');
        print(a);
        cout<<endl;
    }
    return 0;
}
