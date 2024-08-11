#include<bits/stdc++.h>
#include<string>
using namespace std;
int n,a[10000009];
char b[10000009];
int sum=0;
int jiao;
int outt=0;
int main(){
freopen("game.in","r",stdin);
freopen("game.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
  while(outt<n){
        for(int i=0;i<n;i++){
            if(b[i]==b[i+1]){
                for(int j=i;j<n;j++){
                    b[i]=b[i+2];
                }
                sum++;
                outt+=2;
            }
        }

        }
    cout<<sum+1;
    return 0;
}
