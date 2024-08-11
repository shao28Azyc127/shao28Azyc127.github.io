#include<bits/stdc++.h>
using namespace std;
int GENHJ(int m){
    for(int i=m-1;i--;i>1){
        if(m%(i*i)==0) return i
    }
}
int main(){
    int T,M;
    cin >> T >> M;
    for(int i=0;i++;i<T){
        int a,b,c;
        cin >> a >> b >> c;
        int dr=b*b-4*a*c;
        if(dr>0){
            if(-b%(2*a)==0){
                for(int j=1;j++;j<=dr/2){
                        if(j*j==dr) cout << -b/(2*a) << "+" << j;
                        else
                }
            }
            else{

            }
        }
    }
    return 0;
}