#include <iostream>
#include <fstream>
using namespace std;
int t,m,a,b,c,ans[5005];
int main(){
    ifstream inFile("upe.in");
    inFile>>t>>m;
    ofstream outFile("upe.out");
    for(int i=1;i<=t;i++){
        inFile>>a>>b>>c;
        if(b*b-4*a*c<0){
            ans[i]=-1;
        }
        else{
            for(double j=m;j>=1;j-=0.1){
                if(a*a*j+b*j+c==0){
                    ans[i]=j;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=t;i++){
        outFile<<ans[i]<<endl;
    }
    inFile.close();
    outFile.close();
    return 0;
}
