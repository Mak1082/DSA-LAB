#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node2
{
	public:
		int freq2;
		char ch2;
		Node2* left;
		Node2* right;
};

void huffmanCoding(vector<Node2*> arr, vector<int> ftemp, vector<char>ctemp,int n)
{
	//Sorting the arrays based on their frequency
	int i,j,k;
	for(i=0;i<n;i++)
	{
		arr[i]->freq2=ftemp[i];
		arr[i]->ch2=ctemp[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]->freq2>arr[j+1]->freq2)
			{
				swap(arr[j],arr[j+1]);
			}
		}
	}
	
	//Copying only the freq and ch of arr into arr2
	vector<Node2*> arr2;
	Node2* temp= new Node2();
	for(i=0;i<n;i++)
	{
		temp->ch2=arr[i]->ch2;
		temp->freq2=arr[i]->freq2;
		temp->left=NULL; temp->right=NULL;
		arr2.push_back(temp);
	}	
	for(i=0;i<n;i++)
	{
		cout<<arr2[i]->freq2;
	}
	Node2* root= new Node2();
	for(i=0;i<n;i++)
	{
		Node2* l=arr[0]; Node2* r=arr[1];
		cout<<arr[0]->freq2<<" "<<arr[0]->freq2<<endl;
		root->freq2=arr2[0]->freq2+arr2[1]->freq2;
		root->left=l; root->right=r;
		root->ch2='#';
		j=0;
		while(root->freq2>arr2[j]->freq2 && j<n-1)
		{
			arr2[j]=arr2[j+1];
			j++;
		}
		if(j==arr2.size())
		arr2.push_back(root);
		arr2[j-1]=root;
		arr2.erase(arr2.begin());
		n=arr2.size();
		for(k=0;k<n;k++)
		{
			cout<<arr2[k]->freq2<<" ";
		}
	}
	cout<<"SIZE"<<n<<endl;
  for(i=0;i<2;i++)
  cout<<arr2[i]->freq2<<" ";
}

int main()
{
	int n,i,f; char c;
	cout<<"Enter no. of characters"<<endl;
	cin>>n;
	vector<int>ftemp;
	vector<char>ctemp;
	vector<Node2*> arr;
	cout<<"Enter character and its frequency"<<endl;
	Node2* temp=new Node2();
	for(i=0;i<n;i++) arr.push_back(NULL);
	for(i=0; i<n; i++)
	{
		cin>>c; cin>>f;
		temp->ch2=c;
		temp->freq2=f;
		temp->left=NULL;
		temp->right=NULL;
		arr[i]=temp;
		ftemp.push_back(f);
		ctemp.push_back(c);
	}
	for(i=0;i<n;i++)
	{
		arr[i]->freq2=ftemp[i];
		arr[i]->ch2=ctemp[i];
		cout<<arr[i]->ch2;
		cout<<arr[i]->freq2;
	}
	huffmanCoding(arr,ftemp,ctemp, n);
}
