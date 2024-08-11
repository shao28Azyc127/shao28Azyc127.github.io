#include <bits/stdc++.h>
using namespace std;

int cmp(int a,int b){
    if(a<b)
        return true;
    else
        return false;
}

int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int a[1005][1005]={0};
    int i,j;
    int n,m;
    char s[1005][1005];
    int c[1005]={0};
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>s[i];
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            a[i][j]=s[i][j]-'a';
        }
    }
    for(i=0;i<n;i++){
        sort(a[i],a[i]+m,cmp);
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            c[i]+=a[i][j];
        }
    }
    int t;
    int p=1e8;
    for(i=0;i<n;i++){
        if(c[i]<p){
            p=c[i];
            t=i;
        }
    }
    //cout<<a[t][0]<<endl;
    for(i=0;i<n;i++){
        if(a[i][0]>a[t][0])
            printf("%d",0);
        else
            printf("%d",1);
    }
    return 0;
}
