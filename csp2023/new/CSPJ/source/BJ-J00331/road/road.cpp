#include<bits/stdc++.h>
using namespace std;
int n,d,f,cost;
int v[10005];
int pri[10005];
struct lent{
    int a;
    int pos;
}len[10005];
bool cmp(lent x,lent y){
    return x.a<y.a;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>len[i].a;
        len[i].pos=i;
        pri[i]=len[i].a;
    }
    sort(len+1,len+1+n,cmp);
    if(len[1].pos!=1){
        int l=1,r=1;
        while(r<=n){
            while(0){
                r++;
                if(pri[l]>pri[r+1]){
                    break;
                }
            }
            long long k=0;
            for(int i=l;i<r;i++){
                k=k+v[i];
            }
            if(k%d==0){
                f=f+k%d;
            }
            else f=f+(k%d)+1;
            cost=cost+f*pri[l];
            l=r;
            if(pri[r]=len[1].a&&r<n){
                long long mt=0;
                for(int i=r;i<=n;i++){
                    mt=mt+v[i];
                }
                if(mt%d==0){
                    f=f+k%d;
                }
                else f=f+(mt%d)+1;
                cost=cost+f*len[1].a;
                break;
            }
        }
    }
    else{
        long long k=0;
        for(int i=1;i<=n;i++){
            k=k+v[i];
        }
        if(k%d==0){
            f=f+k%d;
        }
        else f=f+(k%d)+1;
        cost=cost+f*len[1].a;
    }
    cout<<cost;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
