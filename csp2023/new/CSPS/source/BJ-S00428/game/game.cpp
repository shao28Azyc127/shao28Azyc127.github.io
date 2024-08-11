#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    cin>>s;
    int nut=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            //vector<char> a(80000);
            int a[80000];
            int h=1;
            for(int k=i;k<=j;k++)
            {
                //cout<<s[k];
                /*if(!a.empty())
                {
                    //cout<<"a:"<<a.back();
                    if(s[k]==a.back()) a.pop_back();
                    else a.push_back(s[k]);
                }
                else a.push_back(s[k]);*/
                if(h!=1)
                {
                    //cout<<"a:"<<a.back();
                    if(s[k]==a[h-1]) h--;
                    else a[h++]=s[k];
                }
                else a[h++]=s[k];
                //cout<<" s[k]:"<<s[k]<<" ";
            }
            //if(a.empty()) nut++;
            //cout<<endl;*/
            if(h==1) nut++;
        }
    }
    cout<<nut;
    return 0;
}
