#include<iostream>

using namespace std;

int arra[7]={3,2,1,0,2,5,7};

void Traverse()
{
    for(int i=0;i<7;i++){

        cout<<arra[i]<< " ";
    }
    cout<<endl;
}

int Partition(int low,int high)
{
    int pivot= arra[high];

    int k= low;

    for(int i=low;i<high;i++)
    {
        if(arra[i]<pivot){

            swap(arra[i],arra[k]);

            k++;
        }
    }
    swap(arra[high],arra[k]);

    return k;
}
void quicksort(int low,int high){

    if(low<high){

   int pos= Partition(low,high);

   quicksort(low,pos-1);

   quicksort(pos+1,high);

    }
}
int main()
{
    int low=0;

    int high=6;

    quicksort(low,high);

   Traverse();

   return 0;
}
