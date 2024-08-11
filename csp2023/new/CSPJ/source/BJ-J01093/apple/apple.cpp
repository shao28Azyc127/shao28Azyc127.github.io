#include <iostream>

using namespace std;

int n;
int a[10000];
int m[10000];

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int t=0;
    int h=0;
    int c=0;
    for(int i=1;i<=n;i++){
        if(t==n) break;
        c++;
        for(int j=1;j<=n;j++){
            if(m[j]==1) continue;
            if(m[j]==0){
                h++;
                if(h%3==1){
                    m[j]=1;
                    a[j]=i;
                    t++;
                }
            }
        }
        h=0;
    }
    cout<<c<<" "<<a[n];
    
    return 0;
}
