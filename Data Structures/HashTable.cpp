#include <iostream>

using namespace std;

int primeSmallerThanSize(int n)
{
    int hashno,i,j,c=0;
    for(j=2;j<n;j++)
    {
        for(i=2;i<j;i++)
        {
            if(j%i==0){c=1; break;}
        }
        if(c==0)hashno=j;
        c=0;
    }
    return hashno;
}

void insert(int* h, int item, int size, int prime)
{
    int key1=item%size;
    int key3;
    if(h[key1]==0) h[key1]=item;
    else
    {
        int key2=prime-(item%prime);
        if(h[key2]==0)h[key2]=item;
        else
        {
            for(int i=1;i<size;i++)
            {
                key3=(key1+i*key2)%size;
                if(h[key3]==0){h[key3]=item; break;}
            }
        }
    }
}

void display(int *hashTable, int n)
{
    for(int i=0;i<n;i++)
        if(hashTable[i]!=0)
        cout<<i<<":"<<hashTable[i]<<", ";
    cout<<"\n";
}

int main()
{
    int i,n,j,c=0,data,hashno,ch;
    cout<<"Enter the table size\n";
    cin>>n;
    int* hashTable=new int[n];
    for(i=0;i<n;i++)
    hashTable[i]=0;
    hashno=primeSmallerThanSize(n);
    do
    {
        cout<<"1.Insert, 2.Display, 3.Exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter element\n";
                cin>>data;
                insert(hashTable,data,n,hashno);
                break;
            case 2:
                cout<<"Elements are:\n";
                display(hashTable,n);
                break;
        }
    }while(ch<3);
}
