#include <iostream>
#include <cmath>

using namespace std;

struct Node{
  int coeff;
  int exp;
  Node *next;
};
Node *poly = NULL;

void Create()
{
  Node *t ;
  Node *last ;
  int num;
  int i;

  cout<<"Enter number of terms\n";
  cin>>num;
  cout<<"Enter each term with coeff and exp\n";
  for(i=0;i<num;i++)
  {
    t = new Node;
    cin>>t->coeff>>t->exp;
    t->next = NULL;
    if(poly == NULL)
    {
      poly = t;
      last = t;
    }
    else
    {
      last->next = t;
      last = t;
    }
  }
}

void Display(Node *p)
{
  while(p)
 {
   cout<<p->coeff<<"x"<<p->exp;
   p=p->next;
 }
 cout<<endl;
}

long Eval( Node *p, int x)
{

 long val=0;
 while(p)
 {
 val+=p->coeff*pow(x,p->exp);
 p=p->next;
 }
 return val;

}


int main()
{
 create();
 Display(poly);
 cout<<Eval(poly,1);

 return 0;
}
