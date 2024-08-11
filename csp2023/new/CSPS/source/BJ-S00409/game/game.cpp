#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int n;
char astr[114514];
int dp[8000][114]; // i,j=i pre chars,
long long cache[8001][8001];
// ? is a char
// V is a valid sstr
// so
// V   valid
// ?? valid
// ?V? valid
// ?VV? valid
//map<int,map<int,int>> cache;
long long valids(int l,int r){
    if(cache[l][r])return cache[l][r];
    long long ca=0;
    //printf("")
    if(l==r)return 0; // 1 char nope
    if(l+1==r&&astr[l]==astr[r]){
        //printf("%d to %d is ??\n",l,r);
        return 1; // '??' rule
    }
    //printf("into %d to %d\n",l,r);
    if(astr[l]==astr[r])ca+=valids(l+1,r-1)+1; // '?V?' rule
    else{
        for(int mi=l+1;mi<r-1;++mi){
            ca=max(ca,valids(l,mi)+
        /*ca+=*/valids(mi+1,r));
            //if(mi==4)printf("THIS MI %d\n",ca);
        //printf("l%d r%d m%d ca%d\n",l,r,mi,ca);
        }
    }
    cache[l][r]=ca;
    return ca;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    scanf(" %s",astr+1);
    /*for(int i=1;l<=n;++l){
        for(int r=l+1;r<=n;++r){
            dp[l][r]+=
        }
    }*/
    printf("%lld\n",valids(0,n+1));
}