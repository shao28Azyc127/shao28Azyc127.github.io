//别鞭我了。我是飞舞。

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
void check(){
cout<<"ILOVEWHR";}
struct line{
    long long t,lim;
};
long long sz[1000050];
vector<line>link[1000050];
bool cmp(line a,line b){
    return a.lim>b.lim;
}
struct stu{
    long long p,t;
};
long long n,m,k;
long long q[1000050][3];
long long inq[1000050][3];
long long cnt[3];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    memset(inq,-1,sizeof(inq));
    cin>>n>>m>>k;
    for(long long i=1;i<=m;i++){
        long long u,v,a;
        scanf("%lld%lld%lld",&u,&v,&a);
        sz[u]++;
        link[u].push_back({v,a});
    }
    for(long long st=0;st<=1000050;st+=k){
            //cout<<st<<endl;
    cnt[st%2]=1;
    q[1][st%2]=1;
    cnt[(st+1)%2]=0;
    for(long long t=st;t<=1100050;t++){
            //cout<<cnt[(t+1)%2]<<endl;
        //cout<<"t="<<t<<":"<<cnt[t%2]<<endl;

        cnt[(t+1)%2]=0;
        if(cnt[t%2]==0){
            break;
        }
        for(long long w=1;w<=cnt[t%2];w++){
            long long ff=q[w][t%2];
            //cout<<ff<<":"<<endl;
            if(ff==n&&t%k==0){
                cout<<t;
                return 0;
            }
            for(long long i=0;i<sz[ff];i++){
                long long rec=link[ff][i].t;
                //cout<<rec<<endl;
                if(t<link[ff][i].lim){
                    continue;
                }else{
                    //cout<<"["<<inq[rec][t%2]<<endl;
                    if(inq[rec][t%2]==t)continue;
                    else{
                        inq[rec][(t+1)%2]=t;
                        ++cnt[(t+1)%2];
                        //cout<<cnt[(t+1)%2];
                        q[cnt[(t+1)%2]][(t+1)%2]=rec;
                    }
                }
            }
            //cout<<endl;
        }
        cnt[t%2]=0;
    }
    }
    cout<<-1;
    return 0;
}
