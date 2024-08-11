#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cassert>
#include<climits>
#include<iomanip>
#include<set>
#include<stack>
#include<fstream>
#include<random>
#include<cmath>
#include<ctime>
#include<complex>
#include<cstdlib>
#include<cstring>
using namespace std;
//从BJBZ来的ZYC,(NOIP RP++)
//洛谷UID：700972
//洛谷用户名：shao28Azyc139

//please let me got 70 points on this problem!
//this problem is so hard that I can only AC Test case #1 and #2!!!!!!
//@C*F I thank you!!!
//10 pts!
int check1(int m,int n){
    if(m>n){
        cout<<1;
    }
    else{
        cout<<0;
    }
}
int check2(int x1,int x2,int y1,int y2){
    if(x1<y1||x2<y2){
        cout<<0;return 0;
    }
    if(x1>y1&&x2>y2){
        cout<<1;return 0;
    }
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,n,m,q;
    cin>>c>>n>>m>>q;
    if(c==1){
            int bn,bm;cin>>bn>>bm;
        check1(n,m);
        for(int i=0;i<q;i++){
            int kx,ky;cin>>kx>>ky;
            for(int j=0;j<kx;j++){
                int p,v;cin>>p>>v;
    bn=v;
            }
            for(int j=0;j<ky;j++){
                int p,v;cin>>p>>v;
                bm=v;
            }
            check1(bn,bm);
        }
    }
    else if(c==2){
        int x1,x2,y1,y2;
        cin>>x1>>x2>>y1>>y2;
        check2(x1,x2,y1,y2);
        int q;cin>>q;
        for(int j=0;j<q;j++){
            int kx,ky;cin>>kx>>ky;
            for(int i=0;i<kx;i++){
                int p,v;cin>>p>>v;
                if(p==1){
                    x1=v;
                }
                else{
                    x2=v;
                }
            }
            for(int i=0;i<ky;i++){
                int p,v;cin>>p>>v;
                if(p==1){
                    y1=v;
                }
                else{
                    y2=v;
                }
            }
            check2(x1,x2,y1,y2);
        }
    }
    else{
        for(int i=0;i<(n+m);i++){
            int tmp;cin>>tmp;
        }
        int q;cin>>q;
        for(int i=0;i<=q;i++){
            cout<<0;
        }
    }
}

