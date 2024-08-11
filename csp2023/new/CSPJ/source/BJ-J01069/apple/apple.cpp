#include<iostream>
using namespace std;
bool a[1000000001];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int cnt,day=0,m=0;
    while(1){
        cnt=-1;
        day++;
        bool flag=true;
        for(int i=1;i<=n;i++){
            if(i==n+1){
                i=1;
            }
            if(!a[i]){
                flag=false;
                cnt++;
                if(cnt%3==0){
                    a[i]=true;
                    if(i==n){
                        m=day;
                    }
                }
            }
        }
        if(flag==true){
            day--;
            break;
        }
    }
    cout<<day<<' '<<m;
    return 0;
}
