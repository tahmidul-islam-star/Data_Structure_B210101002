#include<iostream>

using namespace std;

#define loop for(int i=0;i<n;i++)
#define endl '\n'

int searching(int arra[],int n,int value)
{
    loop
    {
        if(arra[i]==value){

            return i;

            break;
        }
    }
    return -1;
}
int main()
{
    int arra[]={2,9,5,4,7,0,8,3};

    int len = sizeof(arra)/sizeof(arra[0]);

    int key= 7;

    int position= searching(arra,len,key);

    if(position != -1) cout<<key<<" is present at index "<<position+1<<endl;

    else cout<<key<<" is not present in Array"<<endl;

    return 0;
}