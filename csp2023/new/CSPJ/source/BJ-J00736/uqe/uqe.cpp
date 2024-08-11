#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    long long int t,m,a,b,c;
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        int ss=pow(b,2)-4*a*c;
        if(ss<0){
            cout<<"NO";
            break;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
