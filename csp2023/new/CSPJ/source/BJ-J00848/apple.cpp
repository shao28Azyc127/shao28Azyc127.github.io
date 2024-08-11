#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n;
int num[1000010];
bool flag=true;
int ans1;

int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
    cin>>n;
    int ans2=0;
//    cout<<"a"<<endl;
    while(flag){
		flag=false;
        ans2++;
        int j=-1;
        for(int i=1;i<=n;i++){
            if(num[i]==1){
                continue;
            }
            j++;
            if(j%3==0){
				flag=true;
                num[i]=1;
//                cout<<i<<' '<<n<<endl;
                if(i==n){
                    ans1=ans2;
                }
            }
        }
    }
    cout<<ans2-1<<' '<<ans1<<endl;


    return 0;
}
