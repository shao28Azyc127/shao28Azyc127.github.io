#include <iostream>

using namespace std;
int n;
string s1,s2,s3;
int ans=0,flag;
void aaa(int dep,int cnt)
{
    if(cnt==0&&flag!=0)
    {
        ans=1;
        //cout<<flag<<"     ";
        return;
    }
    else
    {
        for(int i=0;i<cnt-1;i++)
        {
            if(s2[i]==s2[i+1])
            {

                for(int j=i;j<=cnt-3;j++)
                    s2[j]=s2[j+2];
                flag++;
                aaa(dep+1,cnt-2);
                //s2=s3;
                break;
            }
        }
        if(flag==0)
        {
            ans=0;
            return;
        }
    }
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s1;
    int c=0;
    for(int i=0;i<=n-1;i++)
    {
        for(int j=i;j<=n-1;j++)
        {
            int tem=0;
            for(int k=i;k<=j;k++)
            {
                s2[k-i]=s1[k];
            }
            s3=s2;
            ans=0;
            flag=0;
            if((j-i+1)%2==0)
            {
                //cout<<i<<","<<j<<",";
                //cout<<j-i<<" ";
                aaa(0,j-i+1);
            if(ans==1)c++;

            }

        }
    }
    cout << c<< endl;
    return 0;
}

