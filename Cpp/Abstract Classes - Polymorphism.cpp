#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
class LRUCache : public Cache{
  private:
   void moveTohead(Node* node) {
    if(node == head) return;
    
    if( node-> prev)  node-> prev -> next = node -> next;
    if( node -> next) node -> next -> prev = node ->  prev;
    if (node == tail) tail = node -> prev;
    node-> prev = NULL;
    node-> next = head;
    if (head) head -> prev = node;
    head = node;
    
    if(!tail) tail = head;
  
   }  
    
 void removetail(){
  if (!tail) return;
  mp.erase(tail->key);
  if (tail == head ) {
    delete tail;
    head = tail = NULL;   
  } else { 
    Node* newTail = tail->prev;
    newTail-> next = NULL;
    delete tail;
    tail = newTail;
  }
 } 
  
 void addToHead(Node* node ) {
  node ->prev = NULL;
  node-> next = head;
  if (head) head->prev = node;
  head = node;
  if (!tail) tail = head;
 } 
 public:
  LRUCache(int capacity) {
    cp = capacity;
    head = NULL;
    tail = NULL;
       
  } 
  ~LRUCache() {
    Node* current = head;
    while(current) {
      Node* node = current->next;
      delete current;
      current = node;
    }
  }
  void set(int key, int value) override {
   if (mp.find(key) != mp.end()) {
   Node* node = mp[key];
   node->value= value;
   moveTohead(node);
  } else { 
    if (mp.size() >= cp){
     removetail();
    }
  Node* newNode = new Node(key, value);
  mp[key] = newNode;
  addToHead(newNode);
  }
}
int get(int key) override{
  if(mp.find(key) != mp.end()) {
  Node* node = mp[key];
  moveTohead(node);
  return node->value;
   }
return -1;
  }
};









int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
