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
int Delete(int arr[], int n, int index)
{
    for (int i = index; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    return n - 1;
}

int main()
{
    int arra[100]={1,3,4,5,6,7,8,9,22,55};

    int len= 10;

    cout<<"Before Delete : "<<endl;

    traverse(arra,len);

    int index= 7;

    int n=Delete(arra,len,index);

    cout<<"After Delete "<<index<<" th index value "<<endl;

    traverse(arra,n);

    return 0;
}
