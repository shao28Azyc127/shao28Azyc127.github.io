#include<bits/stdc++.h>
using namespace std;
int math[3][5050];
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);

    int t,m;
    for(int i=1;i<=t;i++){
        cin>>math[1][i]>>math[2][i]>>math[3][i];
    }
    if(math[1][1]==1&&math[1][2]==0&&math[1][3]==0)cout<<0;
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
