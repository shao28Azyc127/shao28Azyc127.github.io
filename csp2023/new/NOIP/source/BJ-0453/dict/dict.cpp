#include <bits/stdc++.h>
using namespace std;
struct maxxx{
    char s;
    int sum;
    int id;
}a[3001];
maxxx maxx1,maxx2;
int n,m;
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin >>n >>m;
    if(n==1){
        cout <<"1";
        return 0;
    }
    for(int i=1;i<=n;i++){
        char tx=char('z'+1);
        int txs=0;
        char minx=char('a'-1);
        int mins=0;
        for(int j=1;j<=m;j++){
            char ss;
            cin >>ss;
            if(ss<tx){
                tx=ss;
                txs=1;
            }else if(ss==tx){
                txs++;
            }
            if(ss>minx){
                minx=ss;
                mins=1;
            }else if(ss==minx){
                mins++;
            }
        }
        //cout <<i <<" " <<tx <<" " <<txs <<'\n';
        a[i].s=tx;
        a[i].sum=txs;
        a[i].id=i;
        if(maxx1.id==0){
            maxx1.s=minx;
            maxx1.sum=mins;
            maxx1.id=i;
        }else if(maxx2.id==0){
            if(minx<maxx1.s || (minx==maxx1.s && mins<maxx1.sum)){
                maxx2.sum=maxx1.sum;
                maxx2.s=maxx1.s;
                maxx2.id=maxx1.id;
                maxx1.s=minx;
                maxx1.sum=mins;
                maxx1.id=i;
            }else{
                maxx2.s=minx;
                maxx2.sum=mins;
                maxx2.id=i;
            }
        }else{
            if(minx<maxx1.s || (minx==maxx1.s && mins<maxx1.sum)){
                maxx2.sum=maxx1.sum;
                maxx2.s=maxx1.s;
                maxx2.id=maxx1.id;
                maxx1.s=minx;
                maxx1.sum=mins;
                maxx1.id=i;
            }else if(minx<maxx2.s || (minx==maxx2.s && mins<maxx2.sum)){
                maxx2.s=minx;
                maxx2.sum=mins;
                maxx2.id=i;
            }
        }
    }
    //cout <<maxx1.id <<" " <<maxx2.id;
    for(int i=1;i<=n;i++){
        if(i!=maxx1.id){
            if(a[i].s<maxx1.s ||(a[i].s==maxx1.s && a[i].sum<maxx1.sum)){
                cout <<"1";
            }else cout <<"0";
        }else{
            if(a[i].s<maxx2.s ||(a[i].s==maxx2.s && a[i].sum<maxx2.sum)){
                cout <<"1";
            }else cout <<"0";
        }
    }
    return 0;
}
