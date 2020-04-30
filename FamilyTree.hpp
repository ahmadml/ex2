#ifndef EX2_FAMILYTREE_HPP
#define EX2_FAMILYTREE_HPP
#include "iostream"
using namespace std;

namespace family{
class node{
    public:
    string data;
    string sex;
    int x;
    node* left;
    node* right;

    node(){
        data="";
        x=0;
        sex="";
        left=NULL;
        right=NULL;
    }
    node(string name):data(name),left(NULL),right(NULL),x(0),sex("")
    {
        }
        node(string name, string sex):data(name),left(NULL),right(NULL),x(0),sex(sex)
       {

        }
         node(const node& n): data(n.data)
        {
            if(n.right != NULL)
                right = new node(*n.right);
            if(n.left != NULL)
                left = new node(*n.left);
        }

        void set_left(string str, string sex)
        {
            if(left != NULL)
                delete left;
            this->left=new node(str,sex);
        }
        node* git_left(){return this->left;}
        node* git_right(){return this->right;}
        void set_right(string str, string sex)
        {
            if(right != NULL)
                delete right;
            this->right=new node(str,sex);
        }
        string gitname(){return data;}
        ~node() {
            if(left != NULL)
                delete left;
            if(right != NULL)
                delete right;
        } 
       
};

class Tree{
    public:

    node *person;

    Tree(string name) {person = new node(name);}
    Tree(const Tree& toCopy): person(new node(*toCopy.person)) {}
    Tree() { this->person = NULL; }

    Tree& addFather(const string person, const string name);
    Tree& addMother(const string person, const string name);
    string relation(const string name);
    string find(string name);
    void display();
    void remove(string name);
    bool addFather1(node* t, string person, string name );
    bool addMother1(node* t, string person, string name );
    bool disp(node* root);
    bool remove_rec(node* & n, string name);  
    node *relation_rec(node *, const string target);
    node *find_rec(node* n,int h,string sex);
    ~Tree(){
      if(this->person!=NULL)
            delete (this->person);
    }     
};
};
#endif //EX2_FAMILYTREE_HPP