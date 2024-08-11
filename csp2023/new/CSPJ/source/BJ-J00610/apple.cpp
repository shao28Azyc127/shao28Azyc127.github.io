#include <iostream>
#include <fstream>
using namespace std;
int n,a[1000005],flag,num,ans,sum;
int main(){
    ifstream inFile("apple.in");
    inFile>>n;
    inFile.close();
    while(!flag){
        num=2;
        flag=1;
        for(int i=1;i<=n;i++){
            if(num>=2 && !a[i]){
                num=flag=0;//8
                            //1 4 7
                            //2 6
                            //3
                            //5
                            //8
                a[i]=1;
                if(i==n){
                   ans=sum;
                }
            }
            else if(!a[i]){
                flag=0;
                num++;
            }
        }
        sum++;
    }
    ofstream outFile("apple.out");
    outFile<<sum<<" "<<ans;
    outFile.close();
    return 0;
}
