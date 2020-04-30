#include"FamilyTree.hpp"
#include <cstring>
using namespace family;

bool Tree::addFather1 (node* t, string person, string name ){ 
    if(t== NULL) return false;
    if((*t).data==person) {
        if(t->left != NULL) throw out_of_range{"there is already a father"};
        t->set_left(name,"male");
        (*(*t).left).x=((*t).x)+1;
        return true;
    }
    if((*t).left!=NULL || (*t).right!=NULL){
    return addFather1(t->git_left(),person,name)|| addFather1(t->git_right(),person,name);
    }
    else return false;
}

bool Tree::addMother1(node* t, string person, string name ){
    if(t== NULL) return false;
    if((*t).data==person) {
        if(t->right != NULL) throw out_of_range{"there is already a mothre"};
        t->set_right(name,"female");
        (*(*t).right).x=((*t).x)+1;
        return true;
    }
    if((*t).left!=NULL || (*t).right!=NULL) 
    return addMother1((*t).left,person,name) || addMother1((*t).right,person,name);
    else return false;
    
}

family::Tree& family::Tree::addFather(const string person, const string name){
    if(addFather1(this->person,person,name)==false) throw out_of_range{"not found"};
    return *this;
}

family::Tree& family::Tree::addMother(const string person, const string name){
   if(addMother1(this->person,person,name)==false) throw out_of_range{"not found"};
    return *this;
}
family::node* family::Tree::relation_rec(node* n,const string target){
    if(n == NULL) return NULL;
    if(n->gitname() == target) return n;
        node* f=relation_rec(n->git_left(),target);
        node* m=relation_rec(n->git_right(),target);
    if(f==NULL) return m;
    return f;
}
string Tree::relation(const string name){
    string name1="me";
    node* n = relation_rec(person,name);
    if(n != NULL){
    if(n->x==1 && n->sex=="male")  name1="father";
    else if(n->x==1 && n->sex=="female")  name1="mother";
    else if(n->x==2 && n->sex=="male")  name1="grandfather";
    else if(n->x==2 && n->sex=="female")  name1="grandmother";
    else if(n->x>2){
        name1="";
        for(int j=2;j<n->x;j++){
            name1+="great-";
        }
        if(n->sex=="male") name1+="grandfather";
        if(n->sex=="female") name1+="grandmother";
    }
    }
    else name1="unrelated";
    return name1;
}

family::node* family::Tree::find_rec(node* n, int h, string sex){
    if(n == NULL) return NULL;
    if(n->x==h && n->sex==sex) return n;
    node* f = find_rec(n->git_left(),h,sex);
    node* m = find_rec(n->git_right(),h,sex);
    if(f==NULL) return m;
    return f;
}

string Tree::find(string name){
    string s,c,sex;
    s="";
    int h = 0;
    if(name =="father" && person->left != NULL) s = (*(*(*this).person).left).gitname();
    else if(name =="mother" && person->right != NULL ) s = (*(*(*this).person).right).gitname();
    else if(name =="grandfather" && (person->left->left != NULL|| person->right->left != NULL)) s = (*(*(*(*this).person).left).left).gitname();
    else if(name =="grandmother" && (person->left->right != NULL || person->right->right != NULL)) s = (*(*(*(*this).person).left).right).gitname();
    else if(name.length()>=17){
        for(int i=0; i<name.length(); i+=6){
            c=name.substr(i,6);
            if(c=="great-") h++;
        }
        if(h==0) throw out_of_range{"The tree cannot handle the '"+ name + "' relation"};
        h+=2;
        c = name.substr(name.length()-11,11);
        if(c=="grandfather"){
            sex="male";
            node* n = find_rec((*this).person,h,sex);
            if(n != NULL) s=n->gitname();
            else throw out_of_range{"The tree cannot handle the '"+ name + "' relation"};
        }
        else if(c=="grandmother"){
            sex="female";
            node* n = find_rec((*this).person,h,sex);
            if(n != NULL) s=n->gitname();
            else throw out_of_range{"The tree cannot handle the '"+ name + "' relation"};
        }
        else throw out_of_range{"The tree cannot handle the '"+ name + "' relation"};
    }
    else  throw out_of_range{"The tree cannot handle the '"+ name + "' relation"};
    
    return s;
}
bool Tree::disp(node* root){
    if(root != NULL) {  
    cout<<(*root).gitname()<<endl;  
    if((*root).left!=NULL || (*root).right!=NULL){ 
    return disp((*root).left) || disp((*root).right);
    }
    return false;
    }
    return false;
}

void Tree::display(){
    node* n = new node();
    n = person;
    disp(person);
}


bool Tree::remove_rec(node* & n, string name){
    if(n==NULL) return false;
    if(n->gitname()==name){
        delete n;
        n = NULL;
        return true;
    }
    else return remove_rec((*n).left,name) || remove_rec((*n).right,name);
}

void Tree::remove(string name){
    if(person->data==name) throw out_of_range{"this is a root"};
    if(remove_rec(person,name)==false) throw out_of_range{"not found"};
   
}
 