#include<iostream> 
#include<algorithm> 
using namespace std; 
  
class Job 
{ 
  public:
   char id;      
   int dead;    
   int profit;
   void input()
   {
     cin>>id; cin>>dead; cin>>profit;
   }  
};

void printJobScheduling(Job a[], int n)
{
  int i,j;
  int profits[n];
  for(i=0;i<n;i++)
  {
    profits[i]=a[i].profit;
  }
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(profits[j]<profits[j+1])
      {
        swap(profits[j],profits[j+1]);
        swap(a[j],a[j+1]);
      }
    }
  }
  int result [n];
  int slot[n];
  for(i=0;i<n;i++) slot[i]=0;
  for(i=0;i<n;i++)
  {
  	for(j=min(n,a[i].dead)-1;j>=0;j--)
  	{
  		if(slot[j]==0)
  		{
  			slot[j]=1;
  			result[j]=i;
  			break;
		}
	}
  }
  cout << "Maximum profit sequence of jobs \n";
  for(i=0;i<n;i++)
  {
  	if(slot[i]==1)
    cout<<a[result[i]].id<<" ";
  }
}

int main()
{
  int n,i;
  cout<<"Enter no. of jobs\n";
  cin>>n;
  Job arr[n];  
  for(i=0;i<n;i++)
  {
    arr[i].input();
  }  
  printJobScheduling(arr, n); 
  return 0; 
} 
