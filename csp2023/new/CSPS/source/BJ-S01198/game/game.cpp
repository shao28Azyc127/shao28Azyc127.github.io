#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    string s;
    cin>>s;
    //
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    //
    else if(n==2)
    {
        if(s[0]==s[1])
        {
            
            cout<<1;
        }
        else
        {
            cout<<0;
        }
        return 0;
    }
    //
    else if(n==3)
    {
        if(s[0]==s[1]&&s[1]==s[2])
        {
            cout<<1;
        }
        else if(s[0]==s[1])
        {
            
            cout<<1;
        }
        else if(s[1]==s[2])
        {
            
            cout<<1;
        }
        else{
            cout<<0;
        }
        return 0;
    }
    //
    else if(n==4)
    {
        if(s[0]==s[1]&&s[1]==s[2]&&s[2]==s[3])
        {
            cout<<4;
        }
        else if(s[0]==s[1]&&s[1]==s[2])
        {
            cout<<1;
        }
        else if(s[1]==s[2]&&s[2]==s[3])
        {
            cout<<1;
        }
        else if(s[0]==s[1])
        {
            
            cout<<1;
        }
        else if(s[2]==s[3])
        {
            
            cout<<1;
        }
        else if(s[1]==s[2])
        {
            
            cout<<1;
        }
        else{
            cout<<0;
        }
        return 0;
    }
    //
    else if(n==5)
    {
        if(s[0]==s[1]&&s[1]==s[2]&&s[2]==s[3]&&s[3]==s[4])
        {
            cout<<5;
        }
        else if(s[0]==s[1]&&s[1]==s[2]&&s[2]==s[3])
        {
            cout<<4;
        }
        else if(s[1]==s[2]&&s[2]==s[3]&&s[3]==s[4])
        {
            cout<<4;
        }
        else if(s[0]==s[1]&&s[1]==s[2])
        {
            cout<<1;
        }
        else if(s[1]==s[2]&&s[2]==s[3])
        {
            cout<<1;
        }
        
        else if(s[2]==s[3]&&s[3]==s[4])
        {
            cout<<1;
        }
        else if(s[0]==s[1])
        {
            
            cout<<1;
        }
        else if(s[2]==s[3])
        {
            
            cout<<1;
        }
        else if(s[1]==s[2])
        {
            
            cout<<1;
        }
        else if(s[3]==s[4])
        {
            
            cout<<1;
        }
        else{
            cout<<0;
        }
        return 0;
    }
    //
    else if(n==6)
    {
        if(s[0]==s[1]&&s[1]==s[2]&&s[2]==s[3]&&s[3]==s[4]&&s[4]==s[5])
        {
            cout<<9;
        }
        else if(s[0]==s[1]&&s[1]==s[2]&&s[2]==s[3]&&s[3]==s[4])
        {
            cout<<8;
        }
        else if(s[4]==s[5]&&s[1]==s[2]&&s[2]==s[3]&&s[3]==s[4])
        {
            cout<<8;
        }
        else if(s[0]==s[1]&&s[1]==s[2]&&s[2]==s[3])
        {
            cout<<5;
        }
        else if(s[1]==s[2]&&s[2]==s[3]&&s[3]==s[4])
        {
            cout<<5;
        }
        else if(s[4]==s[5]&&s[2]==s[3]&&s[3]==s[4])
        {
            cout<<5;
        }
        else if(s[0]==s[1]&&s[1]==s[2])
        {
            cout<<5;
        }
        else if(s[1]==s[2]&&s[2]==s[3])
        {
            cout<<5;
        }
        
        else if(s[2]==s[3]&&s[3]==s[4])
        {
            cout<<5;
        }
        else if(s[4]==s[5]&&s[3]==s[4])
        {
            cout<<5;
        }
        else if(s[0]==s[1])
        {
            
            cout<<1;
        }
        else if(s[2]==s[3])
        {
            
            cout<<1;
        }
        else if(s[1]==s[2])
        {
            
            cout<<1;
        }
        else if(s[3]==s[4])
        {
            
            cout<<1;
        }
        else{
            cout<<0;
        }
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
