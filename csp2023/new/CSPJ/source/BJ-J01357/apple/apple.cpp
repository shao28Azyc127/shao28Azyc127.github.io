#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
   queue <int> a;
   int n,m;
   cin>>n;
   for(int i=1;i<=n;i++){
        a.push(i);
   }
   int i=1;
   while(!a.empty()){
        int l=a.size();
        for(int j=1;j<=l;j++){
            if(j%3==1){
                if(a.front()==n){
                    m=i;
                }
                a.pop();
            }else{
                a.push(a.front());
                a.pop();

            }
        }
        i++;


   }
   cout<<i-1<<" "<<m;
    return 0;
}
