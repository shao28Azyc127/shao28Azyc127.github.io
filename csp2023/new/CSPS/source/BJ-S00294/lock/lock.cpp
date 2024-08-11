#include <iostream>
#include <vector>
using namespace std;
int shu[9][6],c[6],d[6],a,b;
vector<int> st;
int abs(int x,int y){
    if(x>=y)
        return x-y;
    return y-x;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
            cin>>shu[i][j];
    int cnt;
    vector<int>::iterator it;
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                for(int l=0;l<=9;l++){
                    for(int m=0;m<=9;m++){
                        cnt=10000*i+1000*j+100*k+10*l+m;
                        st.push_back(cnt);
                    }
                }
            }
        }
    }
    for(int k=1;k<=n;k++){
        it=st.begin();
        while(it!=st.end()){
            cnt=0;
            a=*it;
            bool flag=true;
            for(int i=5;i>=1;i--){
                b=a%10;
                if(b!=shu[k][i]){
                    cnt++;
                    c[cnt]=shu[k][i]-b;
                    d[cnt]=i;
                }
                a=a/10;
            }
            if(cnt==0 || cnt>2){
                flag=false;
                st.erase(it);
            }
            else if(cnt==2){
                if(c[1]!=c[2] && c[1]+10!=c[2] && c[2]+10!=c[1]){
                    flag=false;
                    st.erase(it);
                }
                else if(abs(d[1],d[2])!=1){
                    flag=false;
                    st.erase(it);
                }
            }
            if(flag)
                it++;
        }
    }
    cout<<st.size()<<endl;
  //  it=st.begin();
 /*   while(it!=st.end()){
        cout<<*it<<" ";
        it++;
    }
 */ return 0;
}
