#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int a[N]={};
    int ayes=n;
    int days=0,dayn=0,dayncnt=0;
    int first=1;
    while(ayes>=1){
        //cout<<"day"<<days+1<<endl;
        days++;
        dayncnt++;
        int cnt=2;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                first=i;
                break;
            }
        }
        for(int i=first;i<=n;i++){
            if(a[i]==0&&cnt>=2){
                a[i]=1;
                ayes--;
                cnt=0;
                //cout<<i<<endl;
                if(i==n) dayn=dayncnt;
            }else if(a[i]==0){
                cnt++;
            }
        }
    }
    cout<<days<<' '<<dayn;
    return 0;
}
