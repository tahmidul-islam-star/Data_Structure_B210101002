#include<iostream>

using namespace std;

void print(int arra[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arra[i]<<" ";
    }
    cout<<endl;
}
void selection_sort(int arra[],int n)
{
    int pos;

    for(int i=0;i<n-1;i++)
    {
        pos= i;

        for(int j= i+1;j<n;j++)
      {
        if(arra[j]<arra[pos])
      {
         pos=j;
        }
        swap(arra[i],arra[pos]);
        }
    }
}
int main()
{
    int n;cin>>n;

    int arra[n];

    for(int i=0;i<n;i++)
    {
        cin>>arra[i];
    }
     print(arra,n);

    selection_sort(arra,n);

    print(arra,n);

    return 0;
}
