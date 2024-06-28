#include<iostream>

using namespace std;

int arra[7]={8,3,2,1,9,0,-2};

void Traverse()
{
    for(int i=0;i<7;i++)
    {
        cout<<arra[i]<<" ";
    }
    cout<<endl;
}

int Partition(int low,int high)
{
    int pivot= arra[low];

    int k= high;

    for(int i=high ;i>low; i--)
    {
        if(arra[i]>pivot)
        {
            swap(arra[i],arra[k]);

            k--;
        }
    }
    swap(arra[low],arra[k]) ;

    return k;
}
void quicksort(int low,int high)
{
    if(low<high)
    {
        int pos= Partition(low,high);

        quicksort(low,pos-1);

        quicksort(pos+1,high);
    }
}
int main()
{
    int low= 0;

    int high = 6;

   quicksort(low,high);

   Traverse();

   return 0;
}
