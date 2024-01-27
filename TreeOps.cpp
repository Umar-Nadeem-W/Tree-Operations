//212052
//Muhammad Umar Nadeem

#include <iostream>
#include <unistd.h>
using namespace std;


class node{

private:

    int value;
    node* left_node;
    node* right_node;

public:


    void set_val(int v){value = v;} // sets value of the current node you're on

    void set_left_node(node* ln){left_node = ln;} // links the current node with the next node by passing the address of
    void set_right_node(node* rn){right_node = rn;}//the next node in the current node

    int get_value(){return value;}              //returns value stored by current node
    node* get_left_node(){return left_node;}     // returns address of next node current node is linked with
    node* get_right_node(){return right_node;}
};


class bst{

private:
    node* root_node;
    node* current_node;
    node* last_current_node;

public:


       bst(){
        root_node = NULL;
        current_node = NULL;
        last_current_node = NULL;
       }
node*get_root(){return root_node;}

    void iinsert(int val)
    {
    node* nn = new node;
    nn->set_left_node(NULL);
    nn->set_right_node(NULL);
    nn->set_val(val);

    if (root_node == NULL){root_node = nn;
    current_node = root_node;}

    else
        {
            current_node = root_node;
            while( current_node != NULL)
                {
                    last_current_node = current_node;
                    if(val < current_node->get_value())
                    {current_node = current_node -> get_left_node();}

                    else {current_node = current_node->get_right_node();}
                }

            if (val < last_current_node->get_value()){last_current_node->set_left_node(nn);}
            else{last_current_node->set_right_node(nn);}
        }

    }

   void Preorder(node * rot)
  {
    if (rot == NULL)
      return;
    cout << rot -> get_value() << " ";
    Preorder(rot -> get_left_node());
    Preorder(rot -> get_right_node());
  }
  void Inorder(node * rooot)
  {
    if (rooot == NULL)
      return;
    Inorder(rooot -> get_left_node());
    cout << rooot -> get_value() << " ";
    Inorder(rooot -> get_right_node());
  }
  void Postorder(node * rtt)
  {
    if (rtt == NULL)
      return;
    Postorder(rtt -> get_left_node());
    Postorder(rtt -> get_right_node());
    cout << rtt -> get_value() << " ";
  }




      node * minval(node * minod) {
    node * curr = minod;
    while (curr -> get_left_node() != NULL) {
      curr = curr -> get_left_node();
    }
    return curr;
  }

 node * maxval(node * maxnod) {
    node * curr= maxnod;
    while (curr -> get_right_node() != NULL) {
      curr = curr -> get_right_node();
    }
    return curr;
  }

    void searchh (node* root_node, int val)
    {

        if (root_node == NULL)
                {cout<<"Value is not present in the tree."<<endl;}

                if(root_node->get_value()== val){cout<<"Value "<<val<<" is present in the tree.";}

                if (root_node->get_value()>val)
                    {
                        searchh(root_node->get_left_node(), val);
                }

                else if (root_node->get_value() < val)
                    {
                    searchh(root_node->get_right_node(),val);
                    }

            }



node* delette (node* rt, int vall)
{
if (rt == NULL){return NULL;}

else if (vall <rt -> get_value()) {rt -> set_left_node(delette(rt->get_left_node(), vall));}
else if (vall >rt ->get_value()){rt->set_right_node(  delette(rt->get_right_node(), vall));}

else
    {
        if(rt ->get_left_node() == NULL){node* temp =rt ->get_right_node(); delete rt;
        return temp;}
        else if(rt->get_right_node() == NULL){node* temp = rt->get_left_node(); delete rt;
        return temp;}
        else  {node* temp = minval(rt->get_right_node());
        rt -> set_val(temp -> get_value());
        rt -> set_right_node(delette(rt -> get_right_node(), temp -> get_value()));
        }
    }

}




};



int main() {
  bst b1;
  int selection;
  int val;
  int choice2;
  do {
    cout << "Please select your desired option." <<endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Print" << endl;
    cout << "5. Exit Program" << endl;
    cin >> selection;

    node * new_node = new node();
    switch (selection) {

    case 1:
	      cout <<"Please the value you wish to insert in the tree: ";
	      cin >> val;
	      b1.iinsert(val);
	      sleep(2);
  system("CLS");
    	break;

    case 2:
      cout<<"1. Miniumun Value. "<<endl<<"2. Maximun Value."<<endl<<"3. Specific value"<<endl;
      cin>>choice2;
      if(choice2==1){
      	cout<<"Minimum value is: "<<b1.minval(b1.get_root())->get_value()<<endl;
  sleep(3);
  system("CLS");
	  }
	  if(choice2==2){
	  	cout<<"Maximum value is: "<<b1.maxval(b1.get_root())->get_value()<<endl;
	  	sleep(3);
        system("CLS");
	  }
	  if(choice2==3){
	  	 cout << " Please enter the value you wish to search: ";
        cin>>val;
        b1.searchh(b1.get_root(),val);
        sleep(3);
        system("CLS");
	  }
      break;
    case 3:

      cout << "Please enter the value you wish to delete in the tree: ";
      cin >> val;
      if (new_node != NULL) {
        b1.delette(b1.get_root(),val);
        cout << "Value Deleted" << endl;
        sleep(2);
      system("CLS");
      } else {
        cout << "Value is not present in the tree." << endl;
        sleep(2);
      system("CLS");
      }

      break;
    case 4:
      	      cout <<"PRE-ORDER: ";
      	      b1.Preorder(b1.get_root());
      	      cout<<endl;
      	      cout <<"IN-ORDER: ";
      	      b1.Inorder(b1.get_root());
      	      cout<<endl;
      	      cout <<"POST-ORDER: ";
      	      b1.Postorder(b1.get_root());
      	      cout<<endl;
      	      sleep(5);
              system("CLS");
      break;
    case 5:
        selection = 0;
        break;

    default:
      cout << "Please enter a valid option." << endl;
    }
  }
  while (selection != 0);
  return 0;
}

