#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k,u[10010],v[10010],a[10010],tiime=0;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>a[i];
        if(tiime<a[i]){
            cout<<-1;
            return 0;
        }
        tiime++;
    }
    if(tiime%k==0){
        cout<<tiime;
        return 0;
    }
        
	cout<<-1;
}
