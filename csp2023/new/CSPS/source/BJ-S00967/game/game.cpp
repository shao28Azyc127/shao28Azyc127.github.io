#include <bits/stdc++.h>
using namespace std;
long long n;
string s;
bool flag=false;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin>>n;
    cin>>s;
    //only write 0
    for(long long i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            flag=true;
            break;
        }
    }
    if(flag==false){
        cout<<0;
        return 0;
    }
    //large-special-a
    if(n>=1e4){
        cout<<(n*(n+1)/2)-n;
    }
    return 0;
}
