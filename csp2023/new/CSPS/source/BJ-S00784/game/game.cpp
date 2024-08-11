#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=2e6+5,L=32;
int m,n=0;
char a[N],s[N<<1];

void init(){
    s[n++]='!';s[n++]='#';
    for(int i=0;i<m;i++){
        s[n++]=a[i];s[n++]='#';
    }
    s[n++]='&';
    // cout<<s<<endl;
}

ll P[N<<1];
void manacher(){
    int R=0,C;
    for(int i=1;i<=n;i++){
        if(i<=R)P[i]=min(P[C]+C-i,P[(C<<1)-i]);
        else P[i]=1;
        while(s[i-P[i]]==s[i+P[i]])P[i]++;
        if(i+P[i]>R){
            R=i+P[i];
            C=i;
        }
    }
}
// TODO: N<<1
int isin[N],cnt=0;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&m);
    scanf("%s",a);
    init();manacher();
    ll ans=0;

    for(int i=1;i<=m;i++){
        int pos=i*2+1;
        if(P[pos]&1){
            int len=(P[pos]-1)>>1;
            ans+=len;
            if(!len)continue;
            cnt++;
            for(int j=i-len+1;j<=i+len;j++){
                isin[j]=cnt;
            }
        }
    }
    // for(int i=1;i<=m;i++)cout<<isin[i]<<" ";
    int i=1;
    while(i<=m){
        if(isin[i]==0){i++;continue;}
        int j=i,k=isin[i],num=0;
        while(j<=m&&isin[j]){
            if(isin[j]!=k){
                k=isin[j];
                num++;
                ans+=num;
            }
            j++;
        }
        i=j+1;
    }
    printf("%lld",ans);
    return 0;
}