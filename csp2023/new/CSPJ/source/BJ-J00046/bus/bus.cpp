#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    srand(clock());
    cout<<rand()%m+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

