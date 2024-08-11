include<bits/cstd.h++>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,num,flag=0,fv,v;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=i+1;
    }
    while(num!=0){
        num=0;v=1;
        for(int i=0;i<n;i++){
            if(a[i]!=0&&v%3==1){
                if(i==n-1){
                    fv=flag;
                }
                a[i]=0;
            }
            sum+=a[i];
        }
        flag+=1;
    }
    cout<<flag<<" "<<fv;
    return 0;
}
