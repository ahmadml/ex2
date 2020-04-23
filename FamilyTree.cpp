#include"FamilyTree.hpp"
using namespace family;

bool Tree::addFather1 (node* t, string person, string name ){ 
    if((*t).data==person) {
        (*t).left = new node(name,"male");
       // cout<<"f"<<endl;
        (*(*t).left).x=((*t).x)+1;
        return true;
    }
    if((*t).left!=NULL || (*t).right!=NULL){
    return addFather1((*t).left,person,name)|| addFather1((*t).right,person,name);
    }
    else return false;
}

bool Tree::addMother1(node* t, string person, string name ){
    if((*t).data==person) {
        (*t).right = new node(name,"female");
        (*(*t).right).x=((*t).x)+1;
        //cout<<"m"<<endl;
        return true;
    }
    if((*t).left!=NULL || (*t).right!=NULL) 
    return addMother1((*t).left,person,name) || addMother1((*t).right,person,name);
    else return false;
    
}

bool Tree::relation(node* n, string name, int* i, string *s){
    if(n != NULL){
    if((*n).data==name){
       // cout<<"s"<<endl;
        if((*n).sex=="male") *s="male";
        else *s="female";
        *i=(*n).x;
        return true;
    }
    if((*n).left != NULL || (*n).right != NULL) 
    return relation((*n).left,name,i,s) || relation((*n).right,name,i,s);
    else return false;
    }
    else return false;
}


Tree Tree::addFather(string person, string name){
    addFather1((*this).person,person,name);
    return *this;
}

Tree Tree::addMother(string person, string name){
   addMother1((*this).person,person,name);
    return *this;
}

string Tree::relation(string name){
    int *i;
    string *s;
    string name1="me";
    
    if(relation((*this).person,name,i,s)){
        if(*i==1 && *s=="male") name1="father";
        else if(*i==1 && *s=="female") name1="mother";
        else if(*i==2 && *s=="male") name1="grandfather";
        else if(*i==2 && *s=="female") name1="grandmother";
        else if(*i>2){
            name1="";
        for(int j=2;j<*i;j++){
            name1+="great-";
        }
        if(*s == "male") name1+="grandfather";
        if(*s == "female") name1+="grandmother";
        }
    }
    else name1="unrelated";
    return name1;
}

string Tree::find(node* n, int h, string sex){
    if(n != NULL){
        if((*n).x==h && (*n).sex == sex){
             return (*n).gitname();
        }
        else{
            if((*n).left != NULL || (*n).right != NULL){
            return find((*n).right,h,sex) + find((*n).left,h,sex);
            }
            else return "";
        }  
    }
    else return "";

}

string Tree::find(string name){
    string s,c,sex;
    int h = 0;
    if(name =="father") s = (*(*(*this).person).left).gitname();
    else if(name =="mother") s = (*(*(*this).person).right).gitname();
    else if(name =="grandfather") s = (*(*(*(*this).person).left).left).gitname();
    else if(name =="grandmother") s = (*(*(*(*this).person).left).right).gitname();
    else if(name.length()>=17){
        for(int i=0; i<name.length(); i+=6){
            c=name.substr(i,6);
            if(c=="great-") h++;
        }
        h+=2;
        c = name.substr(name.length()-11,11);
        if(c=="grandfather"){
            sex="male";
            s=find((*this).person,h,sex);
        }
        else if(c=="grandmother"){
            sex="female";
            s=find((*this).person,h,sex);
        }
        else throw std::out_of_range{"The tree cannot handle the '"+ name + "' relation"};

    }
    else  throw std::out_of_range{"The tree cannot handle the '"+ name + "' relation"};
    
    return s;
}
void Tree::disp(node* root, int n){
    if(root == NULL) return;  
    cout<<(*root).gitname()<<"\n";  
    if((*root).left!=NULL || (*root).right!=NULL) 
    disp((*root).left,n);
    disp((*root).right,n);
}

void Tree::display(){
    disp(person,0);
}

void Tree::freeALL(node* t){
    if((*t).left){
        freeALL((*t).left);
    }
    if((*t).right){
        freeALL((*t).right);
    }
    if(!(*t).left && !(*t).right) delete(t);
}


void Tree::remove_sub(node* t,string name){
    if((*t).left){
        if((*(*t).left).data==name){
            freeALL((*t).left);
            (*t).left=NULL;
        }
        else remove_sub((*t).left,name);
    }
    if((*t).right){
        if((*(*t).right).data==name){
            freeALL((*t).right);
            (*t).right=NULL;

        }
        else remove_sub((*t).right,name);
    }

  

}

void Tree::remove(string name){
    if(relation(name)=="unrelated") 
        throw std::out_of_range{"The tree cannot handle the '"+ name + "' relation"};
    if((*person).data==name) throw std::out_of_range{"this is a root"};
    if((*person).left){
        if((*(*person).left).data==name){
            freeALL((*person).left);
            (*person).left=NULL;
        }
        else remove_sub((*person).left,name);
    }
    if((*person).right){
        if((*(*person).right).data==name){
            freeALL((*person).right);
           (*person).right=NULL;

        }
        else remove_sub((*person).right,name);
    }
}
 