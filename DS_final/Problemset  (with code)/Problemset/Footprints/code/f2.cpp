#include<iostream>
#include<string>
using namespace std;
int main()
{
    int m;    cin>>m;
    for(int i=1;i<=m;i++)
    {
        string s;    cin>>s;
        int idx=0,ans=0,tmp=0;
        while(s[idx]!='a'&&ans<s.size())
            ans++ , idx = (idx+s[idx]-'0')%s.size() , s[tmp]='a' , tmp=idx;
        if(ans==s.size())
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}