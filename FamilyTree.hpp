#pragma once
#include "iostream"
using namespace std;

namespace family{
class node{
    public:
    string data;
    node* left;
    node* right;
    node(){
        data="";
        left=NULL;
        right=NULL;
    }
    node(string name){
        data=name;
        left=NULL;
        right=NULL;
        }
};

class Tree{

    node person;
    int size;

    public:

    Tree(string name) {
        node n(name);
        person=n;
    }
    Tree addFather(string person, string name);
    Tree addMother(string person, string name);
    string relation(string name);
    string find(string name);
    void display();
    void remove(string name);        
};
};