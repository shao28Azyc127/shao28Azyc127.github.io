#include<bits/stdc++.h>
using namespace std;
const int N=1000000005;
bool a[N];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int num = 0;
    if(n>=1&&n<=3){
        cout<<n<<" "<<n;
        return 0;
    }
    int k=n;
    while(true){
        int k1 = 0;
        num++;
        if(k%3){
            k1 = k/3+1;
        }else{
            k1 = k/3;
        }

        k-=k1;
        if(k==1){
            cout<<++num<<" ";
            break;
        }
    }
    if(n%3 == 1){
        cout<<1;
        return 0;
    }
    //cout<<endl;
    int sum=3;
    bool flag=false;
    for(int i=0;i<num+1;i++){
        if(!flag){
            for(int j=0;j<n;j+=3){
                if(a[j]==false){
                    a[j]=true;
                    //cout<<j+1<<" ";
                    sum=1;
                }
                if(a[n-1] == true){
                    cout<<++i;
                    return 0;
                }
            }
            flag++;
        }
        sum=3;
        for(int j=0;j<n;j++){
            if(a[j]==false&&sum==3){
                a[j]=true;
                //cout<<j+1<<" ";
                sum=1;
            }else if(a[j]==false){
                sum++;
            }
            if(a[n-1] == true){
                cout<<i+2;
                return 0;
            }
        }
    }
    return 0;
}
