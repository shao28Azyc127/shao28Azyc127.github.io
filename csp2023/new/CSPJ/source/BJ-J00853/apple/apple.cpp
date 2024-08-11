#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    cin>>n;
    long long d=1,ans=0,ansd;
    while(1){

        if(n%3==1){
            if(!ans)
            ans=d;
            n/=3;
            n*=2;
        }
        else if(n%3==0){
                //cout<<"%3=0\n";
            n/=3;
            n*=2;
        }
        else if(n%3==2){
            n/=3;
            n*=2;
            n++;
        }
        //cout<<n<<endl;

        if(n==0){
            ansd=d;
            cout<<ansd<<" "<<ans;
            return 0;
        }
        d++;
    }
    return 0;
}
