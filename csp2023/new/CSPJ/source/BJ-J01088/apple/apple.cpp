#include<iostream>
using namespace std;
int m[10000005];
int main(){
    ios::sync_with_stdio(0);
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int re=n;
    int cnt=0;
    while(re!=0){
        cnt++;
        int k=0;
        for(int i=1;i<=n;i++){
            if(!m[i]){
                k++;
                if(k%3==1){
                    m[i]=cnt;
                    re--;
                }
            }
        }
    }
    cout<<cnt<<' '<<m[n];
    return 0;
}
