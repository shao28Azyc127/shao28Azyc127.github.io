# include <bits/stdc++.h>
using namespace std;
int n,m;
string s[3005];
string w[3005];
bool p(string a,string b){
    int l = m;
    for(int i=0;i<l;i++){
        if(int(b[i])<int(a[i])) return 0;
        else if(int(b[i])>int(a[i])) return 1;
    }
    return 1;
}
string cl(string a){
    int l = m;
    for(int i=0;i<l-1;i++){
        for(int j=i+1;j<l;j++){
            if(int(a[i])>int(a[j])) swap(a[i],a[j]);
        }
    }
    return a;
}
int pd(string a,int t){
    for(int i=1;i<=n;i++){
        if(w[i]==s[t]) continue;
        if(p(a,w[i])==0) return 0;
        else return 1;
    }
    return 1;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        cin>>s[i];
        w[i] = s[i];
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(p(w[i],w[j])==0) swap(w[i],w[j]);
        }
    }
    for(int i=1;i<=n;i++){
        string h = cl(s[i]);
        printf("%d",pd(h,i));
    }
    return 0;
}
