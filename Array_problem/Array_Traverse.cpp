#include<iostream>

using namespace std;

void Traverse(int arra[],int len)
{
    for(int i=0;i<len;i++)
    {
    cout<<arra[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arra[]= {1,2,3,4,5,6,7,8,9,10};

    int siz= sizeof(arra)/sizeof(arra[0]);

    Traverse(arra,siz);

    return 0;
}