#include<iostream>

using namespace std;

#define loop for(int i=0;i<n;i++)

void Traverse(int arra[],int n)
{
    loop{

        cout<<arra[i]<<" ";
    }
    cout<<endl;
}

void Bubble_sort(int arra[],int n)
{
    bool ok = false;

    loop
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arra[j]>arra[j+1])
            {
                swap(arra[j],arra[j+1]);

                ok =true;
            }
        }
        if(ok==false) {break;}
    }

}
int main()
{
    int arra[]={2,9,5,4,7,0,8,3};

    int len = sizeof(arra)/sizeof(arra[0]);

    cout<<"Before sorting "<<endl;

    Traverse(arra,len);

    Bubble_sort(arra,len);

    cout<<"After sorting "<<endl;

    Traverse(arra,len);

    return 0;
}
