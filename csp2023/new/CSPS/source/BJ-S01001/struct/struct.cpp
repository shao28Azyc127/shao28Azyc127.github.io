#include<bits/stdc++.h>
using namespace std;
string memo[1000005]; //�ڴ��ӦԪ��(���ڽṹ������Ϊx.y�ṹ)
string name;
int strmemo,strdq; //�ṹ���ڴ棬�ṹ���ڴ����Ҫ��
int k;
map<string,string> strdy,ys; //�ṹ���Ա���ֶ�Ӧ���ͣ�Ԫ��(����)����Ӧ����
map<string,int> memfil,firdir; //��������ռ���ڴ棻Ԫ���ڴ�
void init()
{
    memfil["int"]=4,memfil["short"]=2;
    memfil["long"]=8,memfil["byte"]=1;
    return;
}
string stname[10005],sttype[10005];
int nowmemo=0; //��ǰռ������ڴ�
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    init();
    while(n--)
    {
        int op;
        cin>>op;
        if(op==1) //����ṹ��
        {
            cin>>name;
            cin>>k;
            strdq=0;
            for(int i=1;i<=k;i++)
            {
                string a,b;
                cin>>a>>b;
                strdq=max(strdq,memfil[a]);
                if(strmemo%memfil[a]==0)
                    strmemo+=memfil[a];
                else
                {
                    while(strmemo%memfil[a]!=0)
                        strmemo++;
                    strmemo+=memfil[a];
                }
                strdy[b]=a;
                stname[i]=b;
                sttype[i]=a;
            }
            while(strmemo%strdq!=0)
                strmemo++;
            cout<<strmemo<<" "<<strdq<<endl;
        }
        if(op==2) //����Ԫ��
        {
            //cout<<name<<endl;
            string t,n; //�������ͣ�����
            cin>>t>>n;
            //ys[n]=t;
            if(t==name) //�ṹ��
            {
                for(int i=1;i<=k;i++)
                {
                    //cout<<"NOWMEMO: "<<nowmemo<<endl;
                    string now=sttype[i];
                    int nowm=memfil[now];
                    int ylmemo=nowmemo;
                    if(nowmemo%nowm==0)
                    {
                        ylmemo=nowmemo;
                        nowmemo+=nowm;
                    }
                    else
                    {
                        while(nowmemo%nowm!=0)
                            nowmemo++;
                        ylmemo=nowmemo;
                        nowmemo+=nowm;
                    }
                    //cout<<ylmemo<<" "<<nowmemo<<endl;
                    if(i==1) //��Ԫ����ʼ��ַ
                        cout<<ylmemo<<endl;
                    string nowdir=n+"."+stname[i];
                    firdir[nowdir]=ylmemo;
                    for(int j=ylmemo;j<=nowmemo;j++)
                        memo[j]=nowdir;
                }
            }
            else //��������
            {
                int nowm=memfil[t];
                int ylmemo=nowmemo;
                if(nowmemo%nowm==0)
                    nowmemo+=nowm;
                else
                {
                    while(nowmemo%nowm)
                        nowmemo++;
                    ylmemo=nowmemo;
                    nowmemo+=nowm;
                }
                cout<<ylmemo<<endl;
                string nowdir=n;
                firdir[n]=ylmemo;
                for(int j=ylmemo;j<=nowmemo;j++)
                    memo[j]=nowdir;
            }
        }
        if(op==3) //����Ԫ��
        {
            string ask;
            cin>>ask;
            cout<<firdir[ask]<<endl;
        }
        if(op==4) //�����ڴ�
        {
            int askad;
            cin>>askad;
            if(memo[askad]=="")
                cout<<"ERR\n";
            else
                cout<<memo[askad]<<endl;
        }
    }
}
