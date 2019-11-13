#include<iostream>
#include<list>
using namespace std;

int main()
{
	string s; char ch,ch1;
	int i,j,c;
  cout<<"Enter a string"<<endl;
	cin>>s;
  list<char>qu;
  list<char>st;
  cout<<s.length()<<endl;
	for(i=0;i<s.length();i++)
	{
		ch=s[i];
		c=(int)ch;
		if(c>64 && c<91)
		{
			qu.push_back(ch);
		}
    else if(ch=='*' || ch=='+' || ch=='-' || ch=='/' ||ch=='^')
    {
      if(st.empty()) st.push_front(ch); 
      else
      {
        //1st character
        if(ch=='^')
        {
          if(st.front()!='^') st.push_front(ch);
          else
          {
            qu.push_back(st.front());
            st.pop_front();
            st.push_front(ch);
          }
        }
        //2nd character
        else if(ch=='*' || ch=='/')
        {
          while(st.front()=='^' || st.front()=='/' || st.front()=='*')
          {
            qu.push_back(st.front());
            st.pop_front();
          }
          st.push_front(ch);
        }
        //3rd character
        else if(ch=='+' || ch=='-')
        {
          while(st.front()=='^' || st.front()=='/' || st.front()=='*' || st.front()=='+' || st.front()=='-')
          {
            ch1=st.front();
            qu.push_back(ch1);
            st.pop_front();
          }
          st.push_front(ch);
        }
      }
    }	
	}
  list<char>::iterator x;
  for(x=qu.begin();x!=qu.end();x++)
  {
    cout<<*x;
  }
  list<char>::iterator y;
  for(y=st.begin();y!=st.end();y++)
  {
    cout<<*y;
  }
}
