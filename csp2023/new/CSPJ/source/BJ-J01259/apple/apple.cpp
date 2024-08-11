#include<bits/stdc++.h>
using namespace std;
int q[100000001];
int main(){
freopen("apple.in","r",stdin);
freopen("apple.out","w",stdout);
int a;
cin >>a;
int ans=a;
for(int i = 1;i <=a;i++){
    q[i]=i;
}
bool flag = true;
int cnt = 0,cnt1=0,tianshu;
while(ans>0){
    cnt=0;
    for(int i = 1;i<=a;i++){
        if(q[i]!=0){
            cnt++;
            if(cnt%3==1){
            q[i]=0;
            ans--;
            }
        }
    }
    cnt1++;
   if(q[a]==0&&flag){
    tianshu=cnt1;
    flag = false;
   }
}
cout << cnt1 << " " << tianshu;
fclose(stdin);
fclose(stdout);
return 0;
}