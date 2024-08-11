#include<bits/stdc++.h>

using namespace std;

const int maxk = 1e5+3;

int rightLockNumber[maxk];
int n;

void getLock(int a,int b,int c,int d,int e){
    for(int i=1;i<10;i++)
        rightLockNumber[((a+i)%10*10000+(b+i)%10*1000+(c)*100+(d)*10+(e))]++;
    for(int i=1;i<10;i++)
        rightLockNumber[((a)*10000+(b+i)%10*1000+(c+i)%10*100+(d)*10+(e))]++;
    for(int i=1;i<10;i++)
        rightLockNumber[((a)*10000+(b)*1000+(c+i)%10*100+(d+i)%10*10+(e))]++;
    for(int i=1;i<10;i++)
        rightLockNumber[((a)*10000+(b)*1000+(c)*100+(d+i)%10*10+(e+i)%10)]++;
    for(int i=1;i<10;i++)
        rightLockNumber[((a+i)%10*10000+(b)*1000+(c)*100+(d)*10+(e))]++;
    for(int i=1;i<10;i++)
        rightLockNumber[((a)*10000+(b+i)%10*1000+(c)*100+(d)*10+(e))]++;
    for(int i=1;i<10;i++)
        rightLockNumber[((a)*10000+(b)*1000+(c+i)%10*100+(d)*10+(e))]++;
    for(int i=1;i<10;i++)
        rightLockNumber[((a)*10000+(b)*1000+(c)*100+(d+i)%10*10+(e))]++;
    for(int i=1;i<10;i++)
        rightLockNumber[((a)*10000+(b)*1000+(c)*100+(d)*10+(e+i)%10)]++;
}

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        char a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        getLock(a-'0',b-'0',c-'0',d-'0',e-'0');
    }
    int res=0;
    for(int i=0;i<maxk;i++){
        if(rightLockNumber[i]==n){
            res++;
        }
    }
    cout<<res;
    return 0;
}
