#include "node.h"

class LL {
  nodePtr hol; // head of linked list
  int size;

public:
  LL();
  void insert_node(string, int);
  void print_all();
  ~LL();
};
LL::LL() {
  hol = NULL;
  size = 0;
}

LL::~LL(){
  int i;
  nodePtr t=hol;
  for(i=0;i<size;i++){
    hol=hol->get_next();
    delete t;
    t=hol;
  }
}

void LL::insert_node(string n,int i){
  //1.create a node
  nodePtr new_node=new node(i,n);
  //2. Connect
  if(hol==NULL) hol=new_node;
  else{
    nodePtr t=hol;
    while(t->get_next()!=NULL ) 
      t=t->get_next();
    t->set_next(new_node);
  }size++;
}

void LL::print_all(){
  nodePtr t;
  for(t=hol;t!=NULL;t=t->get_next()){
    t->print();
  }
}