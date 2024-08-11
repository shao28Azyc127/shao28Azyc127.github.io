#include<bits/stdc++.h>
using namespace std;
int N,o;
bool a[1000000000];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>N;
    int cnt=1;
    int tmp;
    int cs=0;
    while(cnt){
        cs++;
        cnt=0;
        tmp=2;
        for(int i=1;i<=N;i++){
            if(!a[i]){
                if(tmp<2) tmp++;
                else{
                    tmp=0;
                    a[i]=1;
                    if(i==N) o=cs;
                }
                cnt++;
            }
        }
    }
    cout<<cs-1<<" "<<o;
    return 0;
}
