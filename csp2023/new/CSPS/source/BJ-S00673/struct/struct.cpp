#include<bits/stdc++.h>
using namespace std;
struct st{
    long long s,e;
};
struct node{
    long long k,maxn;
    string s1[105],name[105];
};
map<string,long long> mp;
map<string,st> a;
map<string,node> str;
string s[100005];
long long n,i,num;
void make(long long x,string name,int op,long long sb){
    num++;
    s[num]=name;
    if(i%x)i=(i/x+1)*x;
    if(op==2)cout<<i<<"\n";
    a[name].s=i;
    a[name].e=i+sb-1;
    i=i+sb;
}
void str_make(string x,string name){
    for(int b=1;b<=str[x].k;b++){
        if(b==1)make(str[x].maxn,name+"."+str[x].name[b],2,mp[str[x].s1[b]]);
        else make(str[x].maxn,name+"."+str[x].name[b],1,mp[str[x].s1[b]]);
    }
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    mp["byte"]=1;
    mp["short"]=2;
    mp["int"]=4;
    mp["long"]=8;
    while(n--){
        int op;
        cin>>op;
        if(op==1){
            string x,s1[105],name[105];
            long long k,maxn=0;
            cin>>x>>k;
            str[x].k=k;
            for(int b=1;b<=k;b++){
                cin>>s1[b]>>name[b];
                str[x].s1[b]=s1[b];
                str[x].name[b]=name[b];
                maxn=max(maxn,mp[s1[b]]);
            }
            str[x].maxn=maxn;
            cout<<maxn*k-maxn+mp[s1[k]]<<" "<<maxn<<"\n";
        }else if(op==2){
            string x,name;
            cin>>x>>name;
            if(mp[x])make(mp[x],name,2,mp[x]);
            else str_make(x,name);
        }else if(op==3){
            string x;
            cin>>x;
            cout<<a[x].s<<"\n";
        }else{
            long long addr,f=0;
            scanf("%lld",&addr);
            for(int b=1;b<=num;b++){
                if(a[s[b]].s>addr)break;
                if(a[s[b]].s<=addr && a[s[b]].e>=addr){
                    cout<<s[b]<<"\n";
                    f=1;
                    break;
                }
            }
            if(f==0)cout<<"ERR\n";
        }
    }
    return 0;
}
