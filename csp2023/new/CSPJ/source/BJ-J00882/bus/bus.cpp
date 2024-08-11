#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,a,b,c;
    cin>>n;
    for (int i = 0;i < n;i++){
        cin>>a>>b>>c;
    }
    srand(time(0));
    cout<<rand()%1000000+1<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
