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
void Insertion_sort(int arra[],int n)
{
    int temp,j;

    for(int i=1;i<n;i++)
    {
        temp= arra[i];

        j = i-1;

        while(arra[j]>temp && j>=0)
        {
            arra[j+1]= arra[j];

            j--;
        }
        arra[j+1]= temp;
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

    Insertion_sort(arra,n);

    print(arra,n);

    return 0;
}
