#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
char s[N];
int n,tt,stk[N];ll ans;
ll solve1(int l,int r){
    int mid=l+r>>1;
    if(l==r) return 0;
    ll t1=solve1(l,mid),t2=solve1(mid+1,r);
    int k1=mid,k2=mid+1;ll res=0,left=0,right=0;
    while(k1>=l&&k2<=r){
            /*
        bool flag=1;
        if(s[k1]!=s[k2]){

        }
        else{
            while(k1>1&&s[k1-1]==s[k1]) k1--;
            while(k2<n&&s[k2+1]==s[k2]) k2++;
            int len=k2-k1+1;
            for(int i=1;i<=len;i++) res+=(len-i+1)/2;
        }*/
        if(k1>l&&s[k1]==s[k1-1]){
            left++;
            k1-=2;
        }
        else if(k2<r&&s[k2]==s[k2+1]){
            right++;
            k2+=2;
        }
        else if(s[k1]==s[k2]){
            res+=left*right+1;
            k1--;k2++;
            left=right=0;
        }
        else return t1+t2+res+right*left;
    }
    tt=0;stk[++tt]=s[l];
    for(int r=l+1;r<=n;r++){
        if(s[r]==stk[tt]) tt--;
        else stk[++tt]=s[r];
        res+=(tt==0);
    }
    return t1+t2+res+right*left;
}

ll solve(int l,int r){
    int mid=l+r>>1;
    ll t1=solve(l,mid),t2=solve(mid+1,r);
    for(int L=1;L<=n;L++){
        tt=0;stk[++tt]=s[l];
        for(int r=l+1;r<=n;r++){
            if(s[r]==stk[tt]) tt--;
            else stk[++tt]=s[r];
            ans+=(tt==0);
        }
    }
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    scanf("%s",s+1);
    printf("%lld",solve1(1,n));
    return 0;
}