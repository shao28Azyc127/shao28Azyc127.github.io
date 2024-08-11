#include<bits/stdc++.h>
using namespace std;
int N,D;
const int NMAX=1e5+7;
struct Z{
    bool yw=0;
    int V,A;
}ZD[NMAX];
bool cmp(Z a,Z b){
    return a.A<b.A;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>N>>D;
    for(int i=1;i<N;i++) cin>>ZD[i].V;
    ZD[N].V=0;
    for(int i=1;i<+N;i++) cin>>ZD[i].A;
    //sort(ZD+1,ZD+N+1,cmp);
    int tmp=1;
    for(int i=2;i<=N;i++){
        if(ZD[i].A>ZD[i-tmp].A){
            ZD[i-tmp].V+=ZD[i].V;
            ZD[i].yw=1;
            tmp++;
        }else tmp=1;
    }
    int o=0;
    double D=0;
    for(int i=1;i<=N;i++){
    //        printf("%f+%d/%d*%d=%f\n",o,ZD[i].V,D,ZD[i].A,1.0*ZD[i].V/D*ZD[i].A);
        if(ZD[i].yw==0){
            double tmp1=1.0*ZD[i].V/D-D;
            if(tmp1==int(tmp1)){
                D=0;
            }else{
                D=int(tmp)+1-tmp;
                tmp=int(tmp)+1;
            }
            o+=tmp*ZD[i].A;
        }
    }
    cout<<o;
    return 0;
}
