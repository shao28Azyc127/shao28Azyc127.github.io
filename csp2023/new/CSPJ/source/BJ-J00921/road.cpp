#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>

using namespace std;

int quzheng(float n){
    int c=int(n);
    if(n>float(c)){
        c++;
    }
    return c;
}
int main()
{
    ifstream cin("road.in");
    ofstream cout("road.out");
    int n,d;
    cin>>n>>d;
    int oilj[10001]={},ju[10000]={};
     int maxju=0;
    for(int i=0;1<n-1;i++){
        cin>>ju[i];
        maxju+=ju[i];
    }
    int minoilj=100000;
    for(int i=0;i<n;i++){
        cin>>oilj[i];
        if(oilj[i]<minoilj){
            minoilj=oilj[i];
        }

    }
    int olibox=0,z;
    int money=0;
    for(int i=1;i<n;i++){
            z=0;
            if(i==n-1){
                break;
            }else if(oilj[i]==minoilj){
                z=quzheng(float(maxju)/float(d))-oilbox;
                money+=z*oilj[i];
                oilbox+=z;
            }else if(oilbox==0){
                 oilbox+=quzheng(float(ju[i])/float(d));
                 money+=oilj[i]*olibox;
            }else if(oilj[i]<oilj[i+1]){
                 z=quzheng(float(ju[i]+ju[i+1])/float(d))
                 money+=z*oilj[i];
                 oilbox+=z;
            }
            else if(oilbox*d<ju[i]){
                z=quzheng(float(ju[i])/float(d))-oilbox;
                oilbox+=z;
                money+=z*oilj[i];
            }
    cout<<money;
    return 0;
}
