#include <iostream>

using namespace std;

template<typename T>
class Stack
{
private:
  T *st;
  int size;
  int top;
public:
  Stack()
  {
    size=10;
    top=-1;
    st=new T[size];
  }
  Stack(int size)
  {
    this->size=size;
    top=-1;
    st=new T[this->size];
  }
  void push(T x);
  T pop();
  T peek(int index);
  int stacktop();
  int isEmpty();
  int isFull();
  void Display();
};


template<typename T>
T Stack<T>::peek(int index)
{
  T x=-1;
  if(top-index+1<0)
  cout<<"Invalid Index"<<endl;
  else
  x=st[top-index+1];

  return x;
}
template<typename T>
int Stack<T>::stacktop()
{
  if(isEmpty())
  return -1;
  return st[top];
}
template<typename T>
int Stack<T>::isFull()
{
  return top==size-1;
}
template<typename T>
int Stack<T>::isEmpty()
{
  return top==-1;
}
template<typename T>
void Stack<T>::push(T x)
{
 if(top==size-1)
 cout<<"Stack overflow\n";
 else
 {
 top++;
 st[top]=x;
 }

}
template<typename T>
T Stack<T>::pop()
{
 int x=-1;

 if(top==-1)
 cout<<"Stack Underflow\n";
 else
 {
 x=st[top--];
 }
 return x;
}
template<typename T>
void Stack<T>::Display()
{
  for(int i=top;i>=0;i--)
  cout<<st[i]<<" ";
  cout<<endl;
}


int main()
{
  Stack<char> stk(6);
  stk.push('a');
  stk.push('b');
  stk.push('c');
  stk.push('d');
  stk.push('e');
  stk.push('f');

  stk.Display();

  cout<<stk.peek(1)<<endl;


  return 0;
}
