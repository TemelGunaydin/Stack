
#include <iostream>
#include <string>

using namespace std;
class Node
{
 int data;
 Node *next;
 Node *top;
 public :
 Node() : top{nullptr}
 {}
 int Eval(string &postfix);
 void push(int x);
 int pop();
 void Display();
 int isBalanced(string &exp);
 int pre(char x);
 int isOperand(char x);
 string *InToPost(string &infix);
};

void Node::push(int x)
{
 Node *t;
 t=new Node;

 if(t==NULL)
 cout<<"stack is full\n";
 else
 {
 t->data=x;
 t->next=top;
 top=t;
 }

}
int Node::pop()
{
 Node *t;
 int x=-1;

 if(top==NULL)
 cout<<"stack is empty\n";
 else
 {
 t=top;
 top=top->next;
 x=t->data;
 delete t;
 }
 return x;
}
void Node::Display()
{
 Node *p;
 p=top;
 while(p!=NULL)
 {
 cout<<p->data<<" ";
 p=p->next;
 }
 cout<<endl;
}

int Node::isBalanced(string &exp)
{
 int i;

 for(i=0;exp[i]!='\0';i++)
 {
 if(exp[i]=='(')
 push(exp[i]);
 else if(exp[i]==')')
 {
 if(top==NULL)
 return 0;
 pop();
 }
 }
 if(top==NULL)
 return 1;
 else
 return 0;
}
int Node::pre(char x)
{
 if(x=='+' || x=='-')
 return 1;
 else if(x=='*' || x=='/')
 return 2;
 return 0;
}

int Node::isOperand(char x)
{
 if(x=='+' || x=='-' || x=='*' || x=='/')
 return 0;
 else
 return 1;

}

string *Node::InToPost(string &infix)
{
 int i=0,j=0;
 string *postfix;
 long len=infix.size();
 postfix=new string[len+2];

 while(infix[i]!='\0')
 {
 if(isOperand(infix[i]))
 postfix[j++]=infix[i++];
 else
 {
 if(pre(infix[i])>pre(top->data))
 push(infix[i++]);
 else
 {
 postfix[j++]=pop();
 }
 }
 }
 while(top!=NULL)
 postfix[j++]=pop();
 postfix[j]='\0';
 return postfix;
}
int Node::Eval(string &postfix)
{
 int i=0;
 int x1,x2,r=0 ;

 for(i=0;postfix[i]!='\0';i++)
 {
 if(isOperand(postfix[i]))
 {
 push(postfix[i]-'0');
 }
 else
 {
 x2=pop();x1=pop();
 switch(postfix[i])
 {
 case '+':r=x1+x2; break;
 case '-':r=x1-x2; break;
 case '*':r=x1*x2; break;
 case '/':r=x1/x2; break;
 }
 push(r);
 }
 }
 return top->data;
}
int main()
{
  Node n{};
  string postfix = "234*+82/-";

 cout<<n.Eval(postfix);

 return 0;
}
