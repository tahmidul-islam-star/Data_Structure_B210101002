#include<iostream>

using namespace std;

int main()
{
    int coun1=0,coun2=0,coun3=0,coun4=0,coun5=0,coun6=0;

    string s;cin>>s;

    bool ok = true;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(') coun1++;

        if(s[i]==')')
        {
            coun2++;

            if(coun1>0 && coun2 >0)
            {
                coun1--; coun2--;
            }
            else {ok = false; break;}
        }
         if(s[i]=='{') coun3++;

        if(s[i]=='}')
        {
            coun4++;

            if(coun3>0 && coun4 >0)
            {
                coun3--; coun4--;
            }
            else {ok = false; break;}
        }
         if(s[i]=='[') coun5++;

        if(s[i]==']')
        {
            coun6++;

            if(coun5>0 && coun6 >0)
            {
                coun5--; coun6--;
            }
        }
         else {ok = false; break;}
    }
    if(ok && coun1==0 && coun2==0 && coun3==0 && coun4== 0 && coun5==0 && coun6==0) cout<<"YES CORRECT"<<endl;

    else cout<<"NO"<<endl;
}
