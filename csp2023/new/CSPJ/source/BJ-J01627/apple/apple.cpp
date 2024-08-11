#include <bits/stdc++.h>

using namespace std;

int main(){
freopen("apple.in","r",stdin);
freopen("apple.out","w",stdout);

long long n,res1=0,res=0,ans=0;

cin>>n;

long long m=n;

while(m!=0){
    if(m%3==1){
        ans=res1+1;
        break;
    }

    if(m%3!=0)m=m-(m/3+1);
    else m=m-(m/3);

    res1++;

}

while(n!=0){
    if(n%3!=0)n=n-(n/3+1);
    else n=n-(n/3);

    res++;
}

cout<<res<<" "<<ans;

return 0;
}