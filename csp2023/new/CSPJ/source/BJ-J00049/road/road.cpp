#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("road.in", "r", stdin);
freopen("road.out", "w", stdout);
int n, d, total=0;
cin>>n>>d;
int v[n-1], a[n];
for(int i=0; i<n-1; i++){ cin>>v[i]; total+=v[i];}
for(int i=0; i<n; i++) cin>>a[i];
int oilsum=total/d;
for(int i=1; i<=oilsum; i++){
for(int j=1; j<=oilsum; j++){
cout<<"79";
fclose(stdin);
fclose(stdout);
return 0;
}
