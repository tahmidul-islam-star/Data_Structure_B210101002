#include<iostream>

using namespace std;

int main()
{
  string s;

  while(cin>>s){
    
  int coun1=0,coun2=0;

  for(int i=0;i<s.size();i++)
  {
      if(s[i]=='(') coun1++;

      else if(s[i]==')'){

        coun2++;

        if(coun1>0){

            coun1--;

            coun2--;
        }
      }
  }
  if(coun1==0 and coun2 ==0) cout<<"correct"<<endl;

  else cout<<"incorrect"<<endl;
  }
  return 0;
}

