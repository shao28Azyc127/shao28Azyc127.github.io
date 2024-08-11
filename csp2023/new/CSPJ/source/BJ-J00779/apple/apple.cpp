#include<bits/stdc++.h>
using namespace std;
long long n,d,m;
bool flag = false;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int s = n;
    while(n > 0){
        d++;
        if((s-1)%3 == 0 && flag == false){
            m = d;
            flag = true;
        }
        n-=1;
        if(n%3 == 0){
            n/=3;
            n*=2;
        }
        else{
            long long t = n%3;
            n/=3;
            n*=2;
            n+=t;
        }
        if(s%3 == 0){
            s-=s/3;
        }
        else{
            s-=s/3;
            s--;
        }
    }
    cout<<d<<' '<<m;
    return 0;
}
