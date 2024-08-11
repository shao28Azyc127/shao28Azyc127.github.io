#include<iostream>
#include<cstring>
#include<set>
using namespace std;
const int N=10;
int n,a[N][N],b[N],h[N];
void init(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++)cin>>a[i][j],h[i]=h[i]*10+a[i][j];
    }
}
inline int get_h(){
    int res=0;
    for(int i=1;i<=5;i++)res=res*10+b[i];
    return res;
}
set<int>s;
inline bool check(){
    s.clear();
    for(int i=1;i<=5;i++){
        for(int j=1;j<10;j++){
            int x=(b[i]+j)%10;
            swap(b[i],x);
            s.insert(get_h());
            swap(b[i],x);
        }
    }
    for(int i=1;i<5;i++){
        for(int j=1;j<10;j++){
            int x=(b[i]+j)%10;
            int y=(b[i+1]+j)%10;
            swap(b[i],x);
            swap(b[i+1],y);
            s.insert(get_h());
            swap(b[i],x);
            swap(b[i+1],y);
        }
    }
    for(int i=1;i<=n;i++)if(!s.count(h[i]))return false;
    return true;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    init();
    int ans=0;
    for(b[1]=0;b[1]<10;b[1]++){
        for(b[2]=0;b[2]<10;b[2]++){
            for(b[3]=0;b[3]<10;b[3]++){
                for(b[4]=0;b[4]<10;b[4]++){
                    for(b[5]=0;b[5]<10;b[5]++){
                        ans+=check();
                    }
                }
            }
        }
    }
    cout<<ans;
    fflush(stdout);
    fclose(stdin);
    fclose(stdout);
    return 0;
}