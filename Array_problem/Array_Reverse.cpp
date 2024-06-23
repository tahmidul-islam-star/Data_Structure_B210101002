#include<iostream>

using namespace std;

void traverse(int arra[],int len)
{
    for(int i=0;i<len ;i++)
    {
        cout<<arra[i]<<" ";
    }
    cout<<endl;
}
void revers(int arra[],int len)
{
    int i=0;

    int j= len-1;

    while(i<j)
    {
        int temp= arra[i];

        arra[i]=arra[j];

        arra[j]=temp;

        i++;

        j--;
    }
}
int main()
{
    int arra[100]={1,3,4,5,6,7,8,9,22,55};

    int len= 10;

    cout<<"Before reverse : "<<endl;

    traverse(arra,len);

    cout<<"After reverse : "<<endl;

    revers(arra,len);

    traverse(arra,len);

    return 0;
}

