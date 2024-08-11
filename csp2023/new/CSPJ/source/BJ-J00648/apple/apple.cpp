#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,ansd,ansn=-1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n){
        ansd++;
        if(n%3==1&&ansn==-1) ansn=ansd;
        n-=(n+2)/3;
    }
    cout<<ansd<<' '<<ansn<<endl;
    return 0;
}
