#include<bits/stdc++.h>
using namespace std;
int a[500000000];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        a[i]=1;
    }
    long long cnt=n;
    long long day=0;
    bool putans=false;
    long long outn;
    while(cnt!=0){
        day++;//day now
        for(long long i=1,nm=0;i<=n;i++){
            if(a[i]==1){
                nm++;
            }
            if(nm%3==1&&a[i]==1){
                cnt--;
                a[i]=0;
            }
            if(a[n]==0&&putans==false){
                outn=day;
                putans=true;
            }
        }
    }
    cout<<day<<' '<<outn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}