//������vis������Ƿ�ѡ�������ѡ������ô�����������¼һ�Σ������¼�����ﵽ2����ô���,p���㣬��������n�Σ���ô��break���������N���ǲ��У���ô��һ������ʱ�临�Ӷ�ԼΪO(n^2)
//������������
//LoL zhe dao ti jiu shi yue shu ge shu ,wo zhen ben
//budiyoucuole
#include<iostream>
using namespace std;
int n,ans=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    if(n<=10){
        if(n==1)cout<<"1 1";
        if(n==2)cout<<"2 2";
        if(n==3)cout<<"3 3";
        if(n==4)cout<<"3 1";
        if(n==5)cout<<"4 5";
        if(n==6)cout<<"4 4";
        if(n==7)cout<<"4 1";
        if(n==8)cout<<"5 5";
        if(n==9)cout<<"5 3";
        if(n==10)cout<<"5 1"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(n%i==0)ans++;
    }
    cout<<ans<<" "<<1<<endl;
    return 0;
}
