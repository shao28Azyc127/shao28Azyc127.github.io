#include<bits/stdc++.h>
using namespace std;
struct ccstation
{
    long long farst;
    long long mony;
    long long qzh;
};
ccstation a[200100];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long nsoil=0;
    long long n,d;
    long long i,j,k;
    cin>>n>>d;
    long long ans=0;
    a[0].qzh=0;
    for(i=2;i<=n;i++)
        cin>>a[i].farst;
    for(i=1;i<=n;i++)
        cin>>a[i].mony;
    for(i=1;i<=n;i++)
        a[i].qzh=a[i-1].qzh+a[i].farst;
    i=1;
    long long soilneed=0;
    while(i!=n)
    {
        for(j=i+1;j<=n;j++)
        {
            if(a[j].mony<a[i].mony)
                break;//�ҳ���һ����Ǯ��������˵ļ���վ
            //else
                //cout<<"::"<<j<<endl;
            if(j==n)
                break;
        }

        long long qzha=a[j].qzh-a[i].qzh;

        if(nsoil>=qzha)//�����ʣ�µ��͹�
            nsoil-=qzha;
        else
        {
            soilneed=ceil((qzha-nsoil)*1.0/d);//���ﵽ��һ������վ��Ҫ��������
            ans+=soilneed*a[i].mony;
           // cout<<i<<" "<<nsoil<<" "<<" "<<qzha<<" "<<soilneed<<" "<<a[i].mony<<" "<<a[i].farst<<" "<<j<<endl;
            nsoil=soilneed*d-(qzha-nsoil);

        }
        i=j;
    }
    cout<<ans;
    return 0;
}
