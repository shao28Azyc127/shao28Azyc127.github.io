#include <iostream>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    unsigned long long input,pos,day=0,anspos;
    bool have=1;
    cin>>input;
    while(input){
        day++;
        pos=(input-1)%3;
        input=(input-1)/3*2;
        input+=pos%2;
        if(have&&(pos==0)){have=0;anspos=day;}
        //cout<<input<<' '<<have<<' '<<day<<' '<<pos<<endl;
        //exit(0);
    }
    if(have) anspos=day;
    cout<<day<<' '<<anspos<<endl;
    return 0;
}