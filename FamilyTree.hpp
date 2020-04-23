#pragma once
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
    public:

    node(){
        data="";
        left=NULL;
        right=NULL;
    }
    node(string name){
        data=name;
        left=NULL;
        right=NULL;
        (*this).x=0;
        (*this).sex="male";
        }
        node(string name, string sex){
        data=name;
        (*this).sex=sex;
        left=NULL;
        right=NULL;
        }
        string gitname(){
         return data;
        }
        ~node (){

        }
};

class Tree{
    public:
    node *person;
    int size;

    public:

    Tree(string name) {
        person = new node(name);
        size = 0;
    }
    Tree addFather(string person, string name);
    Tree addMother(string person, string name);
    string relation(string name);
    string find(string name);
    void display();
    void remove(string name);
    bool addFather1(node* t, string person, string name );
    bool addMother1(node* t, string person, string name );
    bool relation(node* n, string name, int* i, string *s);
    string find(node* n, int h, string sex);
    void freeALL(node* t);
    void remove_sub(node* t,string name);
    void disp(node* root, int n);       
};
};