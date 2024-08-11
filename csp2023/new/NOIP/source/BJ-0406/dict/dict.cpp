#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll N=3e3+10;
ll a[N][N],b[N][2],id,n,m;
bool cmp(char a,char b){
    return a>b;
}
bool cmp2(ll x,ll f){
    for(ll i=1;i<=m;i++){
        if(a[x][i]<b[i][f]) return 1;
        else if(a[x][i]>b[i][f]) return 0;
    }
    return 0;
}
ll det(ll x){
    if(x==id) return ll(cmp2(x,2));
    else return ll(cmp2(x,1));
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=m;i++){
        b[i][1]=b[i][2]=30;
    }
    for(ll i=1;i<=n;i++){
        char word[N];
        scanf("%s",&word);
        sort(word,word+m,cmp);
        for(ll j=1;j<=m;j++){
            a[i][j]=word[j-1]-'a'+1;
        }
        if(cmp2(i,1)){
            id=i;
            for(ll j=1;j<=m;j++){
                b[j][2]=b[j][1],b[j][1]=a[i][j];
            }
        }else if(cmp2(i,2)){
            for(ll j=1;j<=m;j++) b[j][2]=a[i][j];
        }
        sort(word,word+m);
        for(ll j=1;j<=m;j++){
            a[i][j]=word[j-1]-'a'+1;
        }
    }
    if(n==1){
        printf("1"); return 0;
    }
    for(ll i=1;i<=n;i++){
        printf("%lld",det(i));
    }
    return 0;
}
