#include <iostream>
#include<fstream>
#include<algorithm>
#include<math.h>

using namespace std;

int main()
{
    ifstream cin("bus.in");
    ofstream cout("bus.out");
    int n,k,m;
    int u[20001]={},v[20001]={},a[20001]={};
    cin>>n>>k>>m;
    for(int i=0;i<m;i++){
        cin>>u[i]>>v[i]>>a[i];
    }
    int h=0;
    bool fangan=true;
    for(int i=0;i<m;i++){
            if(a[i]+1<a[i+1]){//是否有逗留
                fangan=false;
            }else{//计算方案时间
                h+=1+k;
            }
    }
    if(fangan){
            cout<<h;
        }else{
            cout<<"-1";
        }
    return 0;
}
