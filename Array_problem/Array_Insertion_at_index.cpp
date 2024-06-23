#include<iostream>

using namespace std;

#define endl '\n'

void display(int arra[],int siz)

{
    for(int i=0;i<siz;i++){

        cout<<arra[i]<<" ";
    }
    cout<<endl;
}

int insertion(int arra[],int siz,int element,int capacity,int index)
{
    if(siz>=capacity) return -1;

    for(int i=siz-1; i>=index; i--)
    {
        arra[i+1]=arra[i];
    }
    arra[index]=element;

    return 1;

}
int main()
{
    int arra[100]={1,5,7,8,9,10,11};

    int siz= 7;

    int element=77,index=3;

    display(arra,siz);

    int capacity=100;

    int ok= insertion(arra,siz,element,capacity,index);

    if(ok==-1) cout<<"Insertion is not possible this index"<<endl;

    else{

    siz +=1;

    display(arra,siz);

    }

    return 0;
}
