#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e9+10;
bool ch[maxn];
/*struct Node{
    bool is;
    int num;
}ch[maxn];*/
/*int CT(int n){
    int mul1=1,mul2=2,mul3=3;
    int ct;
    int r=0;
    while(mul1<=n || mul2<=n || mul3<=n){
        mul1+=3;
        if(r==0){
            mul2+=4;
        }
        else {
            mul2+=6;
        }
        if(r==0){
            mul3+=6;
        }
        else {
            mul3+=9;
        }
        if(mul1<=n) ct++;
        if(mul2<=n) ct++;
        if(mul3<=n) ct++;
        r=(r+1)%2;
    }
}*/
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int sum=0,ans=0,cnt=0,t,n,ct=0;
    scanf("%d",&n);
    int nt=n;
    while(nt>2){
        t=nt/3;
        if(nt%3==0) nt-=t;
        else nt-=(t+1);
        cnt++;
    }
    cnt+=nt;
    int mul1=1,mul2=2,mul3=3;
    bool flag = false;
    int r=0;
    while(mul1<=n || mul2<=n || mul3<=n){
        if(mul1==n){
             ans=1;
             break;
        }
        if(mul2==n){
             ans=2;
             break;
        }
        if(mul3==n){
             ans=3;
             break;
        }
        mul1+=3;
        if(r==0){
            mul2+=4;
        }
        else {
            mul2+=6;

        }
        if(r==0){
            mul3+=6;
        }
        else {
            mul3+=9;

        }
        //cout << mul1 << " " << mul2 << " " << mul3 << endl;
        r=(r+1)%2;
    }
    if(ans!=0){
        cout << cnt << " " << ans << endl;
        return 0;
    }
    /*ans=3;
    n=n-CT(n);
    if(ch[n].is) ans+=ch[n].num;
    else{
        n-=CT(n);
        ans=6;
        if(ch[n].is) ans+=ch[n].num;
        else{
            n-=CT(n);
            ans=9;
            if(ch[n].is) ans+=ch[n].num;
        }
        ch[mul1].is=true;
        ch[mul1].num=1;
    }*/
    cout << ans << endl;
}

