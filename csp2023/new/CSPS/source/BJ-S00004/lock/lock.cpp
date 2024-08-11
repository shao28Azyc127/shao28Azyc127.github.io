#include<iostream>
using namespace std;
bool check(int q,int w,int e,int r,int t,int q1,int w2,int e3,int r4,int t5){
    int d=0;
    if(q!=q1)d++;
    if(w!=w2)d++;
    if(e!=e3)d++;
    if(r!=r4)d++;
    if(t!=t5)d++;
    if(d>=3)return false;
    if(!d)return false;
    if(d==1)return true;
    if((q!=q1)&&(w!=w2)&&(((q-q1)==(w-w2))||((q-q1+10)==(w-w2))||((q-q1-10)==(w-w2))))return true;
    if((e!=e3)&&(w!=w2)&&(((e-e3)==(w-w2))||((e-e3+10)==(w-w2))||((e-e3-10)==(w-w2))))return true;
    if((e!=e3)&&(r!=r4)&&(((e-e3)==(r-r4))||((e-e3+10)==(r-r4))||((e-e3-10)==(r-r4))))return true;
    if((t!=t5)&&(r!=r4)&&(((t-t5)==(r-r4))||((t-t5+10)==(r-r4))||((t-t5-10)==(r-r4))))return true;
    return false;
}
int n,a[10][6],ans;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    int b=1;
    for(int j=0;j<=99999;j++){
        int q=j/10000;
        int w=j/1000%10;
        int e=j/100%10;
        int r=j/10%10;
        int t=j%10;
        b=1;
        for(int i=1;i<=n;i++)
        if(!check(q,w,e,r,t,a[i][1],a[i][2],a[i][3],a[i][4],a[i][5]))b=0;
        if(b)ans++;
    }
    cout<<ans;
    return 0;
}