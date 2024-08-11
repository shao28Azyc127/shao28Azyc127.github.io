#include<iostream>

using namespace std;

const int MAXN=1e5+10;
int n,d,v[MAXN],a[MAXN];
int dfs(int i,int lf,int ans);

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>d;
    for(int i=0;i<n-1;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<dfs(0,0,0);

    return 0;
}

int dfs(int i,int lf,int ans){
    if(i==n-1){
        return ans;
    }
    int lo=0;
    for(int k=i;k<n-1;k++){
        lo+=v[k];
    }
    lo-=lf;
    int t1=0;
    while(lo>0){
        lo-=d;
        t1+=a[i];
    }
    for(int j=i+1;j<n;j++){
        if(a[i]<=a[j]){
            continue;
        }
        lo=0;
        for(int k=i;k<j;k++){
            lo+=v[k];
        }
        lo-=lf;
        int t2=0;
        while(lo>0){
            lo-=d;
            t2+=a[i];
        }
        lf=0-lo;
        t2=dfs(j,lf,t2);
        t1=min(t1,t2);
    }

    return ans+t1;
}
