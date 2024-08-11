#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<fstream>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;cin>>n>>d;
    int a[n+20],b[n+20];
    for(int i=0;i<n-1;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int minn=b[0];
    for(int i=0;i<n-1;i++){
        minn=min(minn,b[i]);
    }
    if(b[0]==minn){
        //T11,12,13
        int sum=0;
        for(int i=0;i<n-1;i++){
            sum+=b[i];
        }
        double p=ceil(((double)sum)/d)*a[0];
    }
    else if(n<9){
        //T1,2,3,4,5
        int m=b[0],nowi=0;double pai=0,res=0;
        for(int i=nowi;i<n;i++){
            if(b[i]<m){
                    int sum=0;
                for(int j=nowi;j<i;j++){
                    sum+=a[j];
                }pai+=ceil(((double)sum-res)/d)*b[nowi];
                res=ceil(((double)sum-res)/d)*d+res-sum;
            m=b[i];nowi=i;
            }
        }cout<<fixed<<setprecision(0)<<ceil(pai);
    }
    return 0;
}

