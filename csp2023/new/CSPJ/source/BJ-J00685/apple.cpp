#include<bits/stdc++.h>
using namespace std;
map<int,int> v;
int main (){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    scanf("%d",&n);
    int pos=1,day=0,ansn,cnt=0;
    while(cnt<n){
        //cout<<"j";
        day++;
        pos=1;
        while(v[pos]==1&&pos<=n) pos++;
        //if(pos>n) break;
        if(pos==n) ansn=day;
        cnt++;
        //cout<<pos<<" ";
        v[pos]=1;
        while(pos<n){
                //cout<<"o";
            do{
                pos++;
            }while(v[pos]==1&&pos<=n);
            if(pos>n) break;
            do{
                pos++;
            }while(v[pos]==1&&pos<=n);
            if(pos>n) break;
            do{
                pos++;
            }while(v[pos]==1&&pos<=n);
            if(pos>n) break;
            if(pos==n){
                //cout<<"j";
                ansn=day;
            }
            //cout<<pos<<" ";
            v[pos]=1;
            cnt++;
        }
    }
    //for(int i=1;i<=n;i++) cout<<"i="<<i<<"v[i]="<<v[i]<<endl;
    printf("%d %d",day,ansn);
    //cout<<day<<" "<<ansn;
    return 0;
}
