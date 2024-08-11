#include<iostream>
#include<cstdio>
using namespace std;
int n,num,day_n,day;
bool a[100000005];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    num=n;
    while(num){
        ++day;
        for(int i=1;i<=n;){
            if(a[i]){
                while(a[i])++i;
            }else{
                if(i==n)day_n=day;
                a[i]=1;
                --num;
                while(a[i]&&i<=n)++i;
                ++i;
                while(a[i]&&i<=n)++i;
                ++i;
                while(a[i]&&i<=n)++i;
            }
        }
    }
    cout<<day<<" "<<day_n;
    return 0;
}
