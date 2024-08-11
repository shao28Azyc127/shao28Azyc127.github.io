#include <bits/stdc++.h>
using namespace std;
const int N=10;
int x[N][6];
int n;

int gt(int a,int b){
    if(a<b)return b-a;
    return 9-a+b+1;
}

inline bool isok(int a,int b,int c,int d,int e){
    for(int i=1;i<=n;i++){
        int flag=0;
        if(x[i][0]!=a)flag|=1;
        if(x[i][1]!=b)flag|=2;
        if(x[i][2]!=c)flag|=4;
        if(x[i][3]!=d)flag|=8;
        if(x[i][4]!=e)flag|=16;
        //cout<<a<<','<<b<<','<<c<<','<<d<<','<<e<<"  ;  "<<x[i][0]<<','<<x[i][1]<<','<<x[i][2]<<','<<x[i][3]<<','<<x[i][4]<<" :     "<<flag<<endl;
        if(flag==1||flag==2||flag==4||flag==8||flag==16)continue;
        //cout<<"\t\t"<<gt(x[i][0],a)<<","<<gt(x[i][1],b)<<endl;
        if(flag==3&&gt(x[i][0],a)==gt(x[i][1],b))continue;
        if(flag==6&&gt(x[i][2],c)==gt(x[i][1],b))continue;
        if(flag==12&&gt(x[i][2],c)==gt(x[i][3],d))continue;
        if(flag==24&&gt(x[i][4],e)==gt(x[i][3],d))continue;
        return false;
    }return true;
}

void test(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>x[i][0]>>x[i][1]>>x[i][2]>>x[i][3]>>x[i][4];
    //cout<<isok(0, 0, 1, 6, 0)<<endl;return;
    int ans=0;
    for(int a=0;a<10;a++){
        for(int b=0;b<10;b++){
            for(int c=0;c<10;c++){
                for(int d=0;d<10;d++){
                    for(int e=0;e<10;e++){
                        if(isok(a,b,c,d,e)){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}

signed main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    test();
    return 0;
}
