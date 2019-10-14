#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node
{
	public:
		int freq;
		char ch;
};

void huffmanCoding(Node arr[], int n)
{
	//Sorting the arrays based on their frequency
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j].freq>arr[j+1].freq)
			{
				swap(arr[j],arr[j+1]);
			}
		}
	}
	vector<int>freq;
	for(i=0;i<n;i++)
	{
		freq.push_back(arr[i].freq);
	}
	vector<int> join;
	for(i=0;i<n;i++)
	{
		join.push_back(freq[0]+freq[1]);
		j=0;
		while(join[i]>freq[j] && j<freq.size())
		{
			if(j+1<freq.size())
			freq[j]=freq[j+1];
			j++;
		}
		if(j==freq.size())
		freq.push_back(join[i]);
		freq[j-1]=join[i];
		freq.erase(freq.begin());
		for(k=0;k<freq.size();k++)
		{
			cout<<freq[k]<<" ";
		}
	}
	cout<<"Freq ";
	for(i=0; i<n-1; i++)
	{
		cout<<join[i]<<" ";
	}
}

int main()
{
	int n,i,f; char c;
	vector<int> freq;
	vector<char> ch;
	cout<<"Enter no. of characters"<<endl;
	cin>>n;
	Node arr[n];
	cout<<"Enter character and its frequency"<<endl;
	for(i=0; i<n; i++)
	{
		cin>>c; cin>>f;
		arr[i].ch=c;
		arr[i].freq=f;
	}
	huffmanCoding(arr, n);
}
