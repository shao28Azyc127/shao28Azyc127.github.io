#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ansa,ansb;
bool flag;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    //�ύǰ��ɾ����������������
    //���������⣡����
    cin>>n;
    flag=false;
    if(n%3==1){
        ansb=1;
        flag=true;
    }
    while(n>0){
        if(n%3==0){
            ansa++;
            n-=n/3;
        }
        if(n%3==1){
            ansa++;
            n-=n/3+1;
            if(flag){
                continue;
            }
            else{
                ansb=ansa;
                flag=true;
            }
        }
        if(n%3==2){
            ansa++;
            n-=n/3+1;
        }
    }
    cout<<ansa<<" "<<ansb;
    return 0;
}
//����AKIOI!!!
//���ֱ�ӳ�ʡһ������
