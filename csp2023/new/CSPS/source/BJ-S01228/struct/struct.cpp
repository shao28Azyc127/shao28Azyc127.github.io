#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=105;
map<string,int> ty/*类型对应下表*/,m;//变量lxiabiao
map<string,int> vm;//对应变量名
map<int,string> vm1,vm2;
vector<int> v;
int st[maxn],p=5,l[maxn],lb=0,k[maxn],cnt=1,maxl=0;//k:类型 l:
bool fin(string s){
    int len=s.size();
    for (int i=0;i<len;i++){
        if (s[i]=='.')return 1;
    }
    return 0;
}
string ti(string s){
    int len=s.size();
    for (int i=0;i<len;i++){
        if (s[i]=='.')return s.substr(0,i);
    }
}
string tiqu(string s){
    int len=s.size();
    for (int i=0;i<len;i++){
        if (s[i]=='.')return s.substr(i+1,len-i-1);
    }
}
int get(int p,int k){
    if (p%maxl)p+=maxl-p%maxl;
    int len=v.size();
    for (int i=0;i<=k;i++){
        if (p%l[v[i]]!=0)p=p+l[v[i]]-p%l[v[i]];
        p+=l[v[i]];
    }
    p-=l[v[k]];
    return p;
}
bool sear(int p,int t,int k){
    if (p+l[t]-1<k)return 0;
    else return 1;
}
int se(int p,int k){
    if (p%maxl)p+=maxl-p%maxl;
    int len=v.size();
    for (int i=0;i<len;i++){
        int p0=p;
        if (p%l[v[i]]!=0)p=p+l[v[i]]-p%l[v[i]];
        p+=l[v[i]];
        if (p0<=k&&p>k)return i;
    }
    return -1;
}
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    ty["byte"]=1;
    ty["short"]=2;
    ty["int"]=3;
    ty["long"]=4;
    l[1]=1;l[2]=2;l[3]=4;l[4]=8;

    int n;
    cin>>n;
    while (n--){
        int op;
        cin>>op;
        if (op==1){
            string s;
            int k;
            cin>>s>>k;
            ty[s]=p;
            for (int i=0;i<k;i++){
                string t,n;
                cin>>t>>n;
                v.push_back(ty[t]);
                vm[n]=i;
                vm2[i]=n;
                maxl=max(maxl,l[ty[t]]);
            }
            l[p]=get(0,v.size()-1)+maxl;
            cout<<get(0,v.size()-1)+maxl<<" "<<maxl<<endl;
        }
        if (op==2){
            string t,n;
            cin>>t>>n;
            k[cnt]=ty[t];
            m[n]=cnt;
            vm1[cnt]=n;
            if (ty[t]<=4){
                int p=lb;
                if(p%l[ty[t]])p+=l[ty[t]]-p%l[ty[t]];
                st[cnt]=p;
                lb=p+ty[t];
            }else{
                int len=v.size();
                int x=ty[t];
                int p=lb;
                if (p%maxl)p+=maxl-p%maxl;
                st[cnt]=p;
                if (p%l[x])p+=l[x]-p%l[x];
                p+=l[x];
                lb=p;
            }
            cout<<st[cnt]<<endl;
            cnt++;
        }
        if (op==3){
            string n;
            cin>>n;
            if (fin(n)){
                int a0=m[ti(n)],a1=vm[tiqu(n)];
                cout<<get(st[a0],a1)<<endl;
            }else{
                cout<<st[m[n]]<<endl;
            }
        }
        if (op==4){
            int ad;
            cin>>ad;
            int i=upper_bound(st+1,st+cnt,ad)-st-1;
            int f;
            if (k[i]<=4){
                f=sear(st[i],k[i],ad);
                if (f==1)cout<<vm1[i]<<endl;
                else cout<<"ERR"<<endl;
            }
            else{
                int f=se(st[i],ad);
                if (f!=-1)cout<<vm1[i]<<"."<<vm2[f]<<endl;
                else cout<<"ERR"<<endl;
            }

        }
    }
}