#include<iostream>

using namespace std;

int Partition(int arra[],int low,int high)
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
    swap(arra[low],arra[k]) ; // change pivot

    return k; //new pivot position
}

void quicksort(int arra[],int low,int high)
{

    if(low<high)
    {
        int idx= Partition(arra,low,high);

        quicksort(arra,low,idx-1);

        quicksort(arra,idx+1,high);
    }
}

void print(int arra[])
{
    for(int i=0;i<7;i++)
    {
        cout<<arra[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arra[7]={8,3,2,1,9,0,-2};

    int low= 0;

    int high = 6;

   quicksort(arra,low,high);

   print(arra);

   return 0;
}
