#include <bits/stdc++.h>
using namespace std;
int t,m,a[1005],b[1005],c[1005],drt,sq[40]={0,1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289,324,361,400,441,484,529,576,625,676,729,784,841,900,961};//abc���鲻���ͣ�sqΪƽ�������ڻ����ʽ��drt���б�ʽ
bool have_root,delay;//�ƺ���ûʲô��
int hj(int k){//��ʽ����
    for(int i=1;i<=31;i++){
        if(abs(k)%sq[i]==0){
            k/=sq[i];
        }
    }
    return k;
}
int gcd(int x,int y){//�������
    for(int i=min(x,y)/2;i>=1;i--){
        if(x%i && y%i){
            return i;
        }
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=t;i++){
        drt=b[i]*b[i]-4*a[i]*c[i];
        if(drt>=0){
            have_root=true;
        }
        else{
            have_root=false;
            cout<<"NO"<<endl;
            return 0;
        }//��ʵ��ֱ�ӽ���
        int r=hj(drt);
        int q1= -b[i];
        if(q1==0){//���������ֻ���&���
            delay=true;
        }
        else if(q1%(2*a[i])==0){
            q1/=(2*a[i]);
            cout<<q1<<"+";
        }
        else{
            int g1=gcd(abs(q1),abs(2*a[i]));
            q1/=g1;
            int w1=2*a[i]/g1;
            cout<<q1<<"/"<<w1<<"+";
        }
        int q2=sqrt(abs(drt/r))*(abs(drt/r)/(drt/r));//�������������ֻ������
        if(q2%(2*a[i])==0){
            q2/=(2*a[i]);
            if(q2!=1&&q2!=0){
                cout<<q2<<"*sqrt("<<r<<")";
            }
            else if(q2==1){
                cout<<"sqrt("<<r<<")"
            }
        }
        else{
            int g2=gcd(abs(q2),abs(2*a[i]));
            int w2=2*a[i]/g2;
            q2/=g2;
            if(q2!=0&&q2!=1&&w2!=1){
                cout<<q2<<"*sqrt("<<r<<")/"<<w2;
            }
            else if(q2==1&&w2!=1){
                cout<<"sqrt("<<r<<")/"<<w2;
            }
            else if(q2!=1&&q2!=0&&w2==1){
                cout<<q2<<"*sqrt("<<r<<")";
            }
            else if(q2==1&&w2==1){
                cout<<"sqrt("<<r<<")/"<<w2;
            }
        }
        cout<<endl;
    }
    return 0;
}