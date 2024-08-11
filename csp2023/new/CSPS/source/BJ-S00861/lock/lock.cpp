#include <iostream>
#include <algorithm>
using namespace std;
int a[100005],num[10];
int get_ten(int n){
    int mul=1;
    for (int i=1;i<=n;i++) mul*=10;
    return mul;
}
int get_num(){
    int res=0;
    for (int i=1;i<=5;i++){
        res+=num[i]*get_ten(5-i);
    }
    return res;
}
void tide_up(){
    for (int i=1;i<=5;i++) num[i]=(num[i]+10)%10;
    return;
}

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    int o=n;
    while (o--){
        for (int i=1;i<=5;i++) cin>>num[i];
        for (int i=1;i<=5;i++){
            for (int j=1;j<=9;j++){
                num[i]++;
                tide_up();
                a[get_num()]++;
            }
            num[i]++;
            tide_up();
            if (i!=5){
                for (int j=1;j<=9;j++){
                    num[i]++;
                    num[i+1]++;
                    tide_up();
                    a[get_num()]++;
                }
                num[i]++;
                num[i+1]++;
                tide_up();
            }
        }
    }
    int ans=0;
    for (int i=0;i<=100000;i++){
        ans+=(a[i]==n);
    }
    cout<<ans;
    return 0;
}
