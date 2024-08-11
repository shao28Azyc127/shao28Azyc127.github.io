#include <iostream>
#include <cstring>
using namespace std;
int n,m;
int f1[3001];
int f2[3001];
int ans[3001];
bool check(int i,int j){
    bool pd=1;
    if(f1[i]>=f2[j]) pd=0;
    return pd;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    if(n==1){
        string s;
        cin>>s;
        cout<<1;
    }
    else{
        char ch;
        bool p;
        for(int i=0;i<n;i++){
            int minn=27,maxn=-1;
            for(int j=0;j<m;j++){
                cin>>ch;
                int k=ch-'0'-49;
                minn=min(minn,k);
                maxn=max(maxn,k);
            }
            f1[i]=minn;
            f2[i]=maxn;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                p=1;
                if(j!=i){
                    if(!check(i,j)){
                        p=0;
                        break;
                    }
                }
            }
            ans[i]=p;
        }
        for(int i=0;i<n;i++) cout<<ans[i];
    }
    return 0;
}
//为北京中学高二1+3三班赵晨杰同学征婚 vx:jeffery_zcj
