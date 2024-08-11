#include<bits/stdc++.h>
using namespace std;
int p[100001];
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
int n,d;
cin >> n >> d;
int ans = 0;
for(int i = 0;i <n-1;i++){
    int v;
    cin >>v;
    ans += v;
}
for(int i = 0;i < n;i++){
    cin >>p[i];
}
if(ans%d==0){
    ans/=d;
}else{
ans/=d;
ans++;
}
cout << p[0]*ans;
fclose(stdin);
fclose(stdout);
return 0;
}