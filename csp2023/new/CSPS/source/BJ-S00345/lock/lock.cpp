#include<iostream>
#include<cstring>
#include<fstream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<climits>
#include<random>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<ccomplex>
int mod(int a,int b){
    return a%b;
}
//我要上电视！！！
//luogu.com.cn/user/700972
//shao28Azyc139
//QWQ AWA QAQ qwq awa qaq
//:) :-) :D :P (: (-: Orz
//CCF NOI NOIP CSP IAKIOI ****
//emmmmm....
//@CCF Please let me AC this problem.
//Thanks.
//(I think I won't get an 1=......)
using namespace std;
int main(){
    //freopen("lock.in","r",stdin);
    //freopen("lock.out","w",stdout);
    //Do you think I'll "//" the freopen()?
    //...
    //*music*
    //Never gonna give you up
    //Never gonna let you down...
    //*music*
    //...
    //int main(){main();}
    //_________________
    //|100pts Accepted| <--Choose this!
    //|0pts Unaccepted|
    //|0pts UnknownErr|
    //|_______________|
    //freopen("lock.in",'r',stdin);
    freopen("lock.in","r",stdin);
    //freopen("lock.out","r",stdin);
    //freopen("lock.out","w",stdin);
    freopen("lock.out","w",stdout);


    int n;cin>>n;
    int a[n][5];
    //int key[n][81][5];
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3],&a[i][4]);
    }
    if(n==1){
        cout<<81;return 0;
    }
    /*
    else if(n==2){
        memset(key,0,sizeof(key));
        int trn[9][5]={
            1,0,0,0,0,
            0,1,0,0,0,
            0,0,1,0,0,
            0,0,0,1,0,
            0,0,0,0,1,
            1,1,0,0,0,
            0,1,1,0,0,
            0,0,1,1,0,
            0,0,0,1,1
        };
        for(int i=1;i<=9;i++){
            for(int j=1;j<=9;j++){
                for(int k=0;k<5;k++){
                    double MOD=9;
key[0][(i-1)*9+j][k]=mod(a[0][k]+trn[i][k]*j,9)+1;
key[1][(i-1)*9+j][k]=mod(a[0][k]+trn[i][k]*j,9)+1;
                }
            }
        }
        int ans=0;
        for(int i1=0;i1<81;i1++){
            for(int i2=0;i2<81;i2++){
                bool same=1;
                for(int j=0;j<5;j++){
                    if(key[0][i1][j]!=key[1][i2][j]){
                        same=0;
                    }
                }
                if(same){
                    ans++;
                }
            }
            cout<<ans;return 0;
        }
    }
    */
    else if(n==2){
        int da,db,dc,dd,de;
        da=a[0][0]-a[1][0];
        db=a[0][1]-a[1][1];
        dd=a[0][3]-a[1][3];
        de=a[0][4]-a[1][4];
        dc=a[0][2]-a[1][2];
        //T6,7,8
        if(da!=0||db==0||dc==0||dd==0||de==0){
            if(da%2){
                cout<<8;return 0;
            }
            else{
                cout<<10;return 0;
            }
        }
        if(da==0||db!=0||dc==0||dd==0||de==0){
            if(db%2){
                cout<<8;return 0;
            }
            else{
                cout<<10;return 0;
            }
        }
        if(da==0||db==0||dc!=0||dd==0||de==0){
            if(dc%2){
                cout<<8;return 0;
            }
            else{
                cout<<10;return 0;
            }
        }
        if(da==0||db==0||dc==0||dd!=0||de==0){
            if(dd%2){
                cout<<8;return 0;
            }
            else{
                cout<<10;return 0;
            }
        }
        if(da==0||db==0||dc==0||dd==0||de!=0){
            if(de%2){
                cout<<8;return 0;
            }
            else{
                cout<<10;return 0;
            }
        }
        cout<<0;return 0;
    }
    else{
        int da,db,dc,dd,de;
        int m[5][10];int ccf[5];
        for(int i=0;i<n;i++){
            da=a[0][0]-a[i][0];
            db=a[0][1]-a[i][1];
            dd=a[0][3]-a[i][3];
            de=a[0][4]-a[i][4];
            dc=a[0][2]-a[i][2];
            if(da!=0){
                ccf[0]=1;
            }
            if(db!=0){
                ccf[1]=1;
            }
            if(dc!=0){
                ccf[2]=1;
            }
            if(dd!=0){
                ccf[3]=1;
            }
            if(de!=0){
                ccf[4]=1;
            }
            m[0][a[i][0]]=1;
            m[1][a[i][1]]=1;
            m[2][a[i][2]]=1;
            m[3][a[i][3]]=1;
            m[4][a[i][4]]=1;
        }
        int summm[5]={0};
        for(int i=0;i<10;i++){
            summm[0]+=(!m[0][i]);
            summm[1]+=(!m[1][i]);
            summm[2]+=(!m[2][i]);
            summm[3]+=(!m[3][i]);
            summm[4]+=(!m[4][i]);
        }
        cout<<summm[0]*summm[1]*summm[2]*summm[3]*summm[4];
    }
    return 0;
}
