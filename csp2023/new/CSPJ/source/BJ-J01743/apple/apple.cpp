#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,d1 = 0,d2 = 0;
    cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;++i){
        a[i] = i+1;
    }
    while(!a.empty()){
        n=-2;
        ++d1;
        if(a.size()>=3){
            while(n+3<a.size()){
                n+=3;
                if (a[n]==a.back()){d2 = d1;}
                a.erase(a.begin()+n);
                --n;
            }
        }else{
            d2 = d1 = d1 + a.size() - 1;
            break;
        }
    }
    cout<<d1<<" "<<d2<<"\n";
    return 0;
}