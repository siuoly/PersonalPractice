#include<iostream>
#include<list>
using namespace std;
// 1
struct ListNode{
	int val;
	ListNode* next;

	ListNode():val(0) , next(nullptr){};
	ListNode(int x): val(x), next(nullptr){};
	ListNode(int x, ListNode* ptr): val(x) , next(ptr){};
};

ListNode* node1(){
	ListNode* a = new ListNode(3);
	a = new ListNode(4,a);
	a = new ListNode(2,a);

	return a;	
}
 
ListNode* node2(){
	ListNode* a = new ListNode(4);
	a = new ListNode(6,a);
	a = new ListNode(5,a);

	return a;	
}

ListNode* run(){
	ListNode* l1= node1(), *l2 = node2();
 	int a=0, b=0;
 
  while( l1 )
  {
      a *=10;
      a += l1->val; 
      l1=l1->next;
  }
  
  while( l2 )
  {
      b *=10;
      b += l2->val; 
      l2=l2->next;            
  }
  a+=b;
  
  ListNode *tmp = new ListNode(a/10); a/=10;
  
  while( a!=0 )
  {
      ListNode *current = new ListNode(a/10 , tmp);
      tmp = current;   a/=10;
  }
  
  return tmp;
}

int main(){
	run();

}
