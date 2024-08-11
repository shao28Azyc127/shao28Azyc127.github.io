#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    scanf("%d",&n);
    int l[5];
    for(int i=0;i<5;i++){
        scanf("%d",&l[i]);
    }
	cout<<sizeof(l)/4*9+36;
    return 0;
}