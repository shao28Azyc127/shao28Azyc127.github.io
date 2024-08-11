#include<bits/stdc++.h>
using namespace std;

int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')  f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
const int N=8e3+100;
int l,r;
int st[N];
int n,ans,top;
char t[N];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    n=read();
    scanf("%s",(t+1));
    for(int l=1;l<=n;l++){
        top=1;
        st[top]=t[l]-'a';
        for(int r=l+1;r<=n;r++){
            if(top&&t[r]-'a'==st[top])   top--;
            else st[++top]=t[r]-'a';
            if(top==0)  ++ans;
        }
    }
    printf("%d\n",ans);
    return 0;
}
