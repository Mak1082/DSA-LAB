#include<iostream>
#include<vector>
using namespace std;

void findMin(int cash)
{
  int deno[] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000 };
  int i=8;
  vector<int> notes;
  for(i=8;i>=0;i--)
  {
    while(deno[i]<=cash)
    {
        cash=cash-deno[i];
        notes.push_back(deno[i]);
    }
  }
  for(i=0;i<notes.size();i++)
  {
    cout<<notes[i]<<" ";
  }
}

int main()
{
  findMin(93);
}
