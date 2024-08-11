#include<bits/stdc++.h>
using namespace std;
struct lock{
    int h[9];
    void operator=(const lock dd){
        h[1]=dd.h[1];
        h[2]=dd.h[2];
        h[3]=dd.h[3];
        h[4]=dd.h[4];
        h[5]=dd.h[5];
    }
    bool operator==(const lock dd)const{
        return (h[1]==dd.h[1]&&h[2]==dd.h[2]&&h[3]==dd.h[3]&&h[4]==dd.h[4]&&h[5]==dd.h[5]);
    }
    bool operator<(const lock a2)const{
        int n1,n2;
        n1=h[1]*10000;
        n1+=h[2]*1000;
        n1+=h[3]*100;
        n1+=h[4]*10;
        n1+=h[5]*1;
        n2=a2.h[1]*10000;
        n2+=a2.h[2]*1000;
        n2+=a2.h[3]*100;
        n2+=a2.h[4]*10;
        n2+=a2.h[5]*1;
        return n1<n2;
    }
    bool operator>(const lock a2)const{
        int n1,n2;
        n1=h[1]*10000;
        n1+=h[2]*1000;
        n1+=h[3]*100;
        n1+=h[4]*10;
        n1+=h[5]*1;
        n2=a2.h[1]*10000;
        n2+=a2.h[2]*1000;
        n2+=a2.h[3]*100;
        n2+=a2.h[4]*10;
        n2+=a2.h[5]*1;
        return n1>n2;
    }
}f[109],b[109],a;
int inn;
int jnn;
int n;
/*bool cmp(lock a1,lock a2){
    int n1,n2;
    n1=a1.h[1]*10000;
    n1+=a1.h[2]*1000;
    n1+=a1.h[3]*100;
    n1+=a1.h[4]*10;
    n1+=a1.h[5]*1;
    n2=a2.h[1]*10000;
    n2+=a2.h[2]*1000;
    n2+=a2.h[3]*100;
    n2+=a2.h[4]*10;
    n2+=a2.h[5]*1;
    return n1<n2;
}*/
void mk(){
    jnn=0;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=9;j++){
            ++jnn;
            for(int k=1;k<i;k++){
                b[jnn].h[k]=a.h[k];
            }
                b[jnn].h[i]=(a.h[i]+j)%10;
            for(int k=i+1;k<=5;k++){
                b[jnn].h[k]=a.h[k];
            }
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=9;j++){
            ++jnn;
            for(int k=1;k<i;k++){
                b[jnn].h[k]=a.h[k];
            }
                b[jnn].h[i]=(a.h[i]+j)%10;
                b[jnn].h[i+1]=(a.h[i+1]+j)%10;
            for(int k=i+2;k<=5;k++){
                b[jnn].h[k]=a.h[k];
            }
        }
    }
}
void cl(){
    int nii;
    nii=0;
    for(int i=1;i<=inn;i++){
        for(int j=1;j<=jnn;j++){
            if(f[i]==b[j]){
                f[++nii]=f[i];
                break;
            }
        }
    }
    inn=nii;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int i=1;i<=5;i++){
            cin>>a.h[i];
        }
        mk();
        if(i==1){
            for(int i=1;i<=jnn;i++){
                f[i]=b[i];
            }
            inn=jnn;
        }else{
            cl();
        }
    }
    cout<<inn<<endl;
    return 0;
}
