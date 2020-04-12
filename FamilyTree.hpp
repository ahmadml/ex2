#pragma once
#include "iostream"
using namespace std;

namespace Family{
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
    void addFather(string person, string name);
    void addMother(string person, string name);
    string relation(string name);
    string find(string name);
    void display();
    void remove();        
};
};