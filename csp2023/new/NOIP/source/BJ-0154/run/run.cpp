#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y,v;
}a[100001];

int c,t;
int n,m,k,d;
long long sum,cnt,ans,kl,nl;

bool cmp(node a,node b){
    return a.x < b.x;
}

int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans = 0;
        cin>>n>>m>>k>>d;
        for(int i = 0;i < m;i++){
            cin>>a[i].x>>a[i].y>>a[i].v;
        }
        sort(a,a+m,cmp);
        bool f;
        for(int i = 0;i < (1<<n);i++){
            f = true;
            sum = 0;
            cnt = 0;
            kl = 0;
            nl = 0;
            for(int j = 0;j < n;j++){
                if(i&(1<<j)){
                    sum++;
                    cnt -= d;
                    kl++;
                }else{
                    sum = 0;
                    kl = 0;
                }
                if(kl > k){
                    f = false;
                    break;
                }
                while(a[nl].x == j+1){
                    if(sum >= a[nl].y){
                        cnt += a[nl].v;
                    }
                    nl++;
                }
            }
            if(f == true && cnt > ans){
                ans = cnt;
            }
        }
        cout<<ans;
    }
    return 0;
}
