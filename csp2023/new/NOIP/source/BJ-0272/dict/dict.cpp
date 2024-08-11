#include<bits/stdc++.h>
#define FILE "dict"
#define up(i,l,r) for(int i=l; i<=r; i++)
#define dn(i,l,r) for(int i=l; i>=r; i--)
using namespace std;

inline int read(){
    int f=1,x=0;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
        x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return f*x;
}

typedef long long LL;
typedef unsigned long long ULL;
const int N=3072;

int n,m;

ULL getHash(int bucket[], bool type=0){
    ULL x=0;
    if(type){dn(i,25,0)while(bucket[i]>0)x=(x<<1)+(x<<3)+(x<<4)+i,bucket[i]--;}
    else{up(i,0,25)while(bucket[i]>0)x=(x<<1)+(x<<3)+(x<<4)+i,bucket[i]--;}
    return x;
}

ULL minHashmax=-1;
ULL maxHash[N], minHash[N];

int main(){
    #ifdef FILE
    freopen(FILE".in","r",stdin);
    freopen(FILE".out","w",stdout);
    #endif // FILE
    n=read(),m=read();
    up(i,1,n){
        char s[N];
        int bucket[32]={0},cbucket[32]={0};
        scanf("%s",s);
        up(j,0,m-1)bucket[s[j]-'a']++,cbucket[s[j]-'a']++;
        maxHash[i]=getHash(bucket,1);
        minHash[i]=getHash(cbucket,0);
        minHashmax=min(minHashmax,maxHash[i]);
    }
    up(i,1,n)printf("%d",maxHash[i]!=minHashmax? minHash[i]<minHashmax:1);
    return 0;
}
