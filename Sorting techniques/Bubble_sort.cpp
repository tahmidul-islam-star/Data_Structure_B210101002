#include<iostream>

using namespace std;

#define loop for(int i=0;i<n;i++)

void Traverse(int arra[],int n)
{
    loop
    {
        cout<<arra[i]<<" ";
    }
    cout<<endl;
}
void Bubble_sort(int arra[],int n)
{
    bool ok = false;

    for(int i=0; i<n-1; i++)
    {
        ok= true;

        for(int j=0; j<n-i-1; j++)
        {
            if(arra[j]>arra[j+1])
            {
                swap(arra[j],arra[j+1]);

                ok =true;
            }
        }
        if(ok) {return;}
    }
}
int main()
{
    int n;
    cin>>n;

    int arra[n];

    for(int i=0; i<n; i++)
    {
        cin>>arra[i];
    }
    cout<<"Before sorting "<<endl;

    Traverse(arra,n);

    Bubble_sort(arra,n);

    cout<<"After sorting "<<endl;

    Traverse(arra,n);

    return 0;
}
