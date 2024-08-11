#include <bits/stdc++.h>
using namespace std;
long long ans=0;
int n;
string str;
long long is[2000006];
struct seg
{
    int st;
    int en;
    int subnum;
};
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>str;
    string temp1,temp2;
    vector <seg> segment;
    int st,en;
    seg temp;
    for(int i=1;i<n;i++)
    {
        if(str[i] == str[i-1])
        {
            ans++;
            st=i-1;
            en=i;
            for(int bi=1;i-bi-1>=0 && i+bi<n;bi++)
            {
                if(str[i-bi-1] == str[i+bi] && str[i-bi-1] != str[i-bi-2] && str[i+bi] != str[i+bi+1])
                {
                    ans++;
                    st = i-bi-1;
                    en = i+bi;
                }
                else
                {
                    break;
                }
            }
            temp.st = st;
            temp.en = en;
            i = en+1;
            temp.subnum = 1;
            segment.push_back(temp);
        }
    }
//for(int i=0;i<segment.size();i++)
//    {
//        cout<<segment[i].st<<" "<<segment[i].en<<endl;
//    }
    for(int i=1;i<segment.size();i++)
    {
        //cout<<i;
        if(segment[i].st == segment[i-1].en+1)
        {

            temp.st = segment[i-1].st;
            temp.en = segment[i].en;
            temp.subnum = segment[i].subnum + segment[i-1].subnum;
            //cout<<temp.subnum<<endl;
            segment.erase(segment.begin()+i-1);
            segment.erase(segment.begin()+i-1);
            segment.insert(segment.begin(),temp);
            //cout<<temp.st<<" "<<temp.en<<endl;
            //cout<<segment[0].subnum<<endl;
            i--;
            //cout<<i<<endl;
        }
    }
    int mid=1;
    int jc;

    for(int i=0;i<segment.size();i++)
    {
        //cout<<segment[i].subnum<<endl;
        ans+=(segment[i].subnum * (segment[i].subnum-1))/2;
    }

    cout<<ans;
    return 0;
}
