#include<bits/stdc++.h>
using namespace std;
char a[2000006];
int head[2000006];
int p,ans;
int n;
int maxr,minl;
int maxra[2000006];
int minla[2000006];
int searchlr(int l,int r){
    minl=min(l,minl);
    maxr=max(r,maxr);
    int an=1;
    if(l>=3&&a[l-1]==a[l-2]){an+=searchlr(l-2,r);}
    if(r<=n-2&&a[r+1]==a[r+2]){an+=searchlr(l,r+2);}
    if(l>=2&&r<=n-1&&a[l-1]==a[r+1]){an+=searchlr(l-1,r+1);}
    //cout<<l<<' '<<r<<' '<<an<<endl;
    return an;
}

bool touch(int l,int r){
    return maxra[l]>minla[r];
}

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        if(a[i]==a[i-1]){
            head[++p]=i;
        }
    }
    //cout<<1<<endl;
    for(int i=1;i<=p;i++){
        //cout<<head[i]-1<<' '<<head[i]<<endl;
        minl=head[i-1];
        maxr=head[i];
        ans+=searchlr(head[i]-1,head[i]);
        maxra[i]=maxr;
        minla[i]=minl;
        //cout<<ans<<endl;
    }
    //cout<<2<<endl;
    for(int i=1;i<p;i++){
        int j=i+1;
        while(touch(i,j)){
            ans+=searchlr();
            j++;
            if(j>p){
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}