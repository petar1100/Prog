#include<bits/stdc++.h>
using namespace std;

class BSTvec{

    vector<int> v;
public:
    BSTvec(){v.push_back(-1);}
    ~BSTvec(){}
    void insert(int n){

        int i=1;
        if(v.size()==1){

            v.push_back(n);
            v.resize(v.size()*2,-1);
            return;
        }
        v.resize(v.size()*2,-1);
        while(v[i]!=-1){

            if(v[i]>n){
                i*=2;
            }
            else{
                i*=2;
                i++;
            }
        }
        v[i]=n;
    }
    void preorder(int i=1){

        if(v[i]==-1){
            return;
        }
        cout<<v[i]<<" ";
        preorder(i*2);
        preorder(i*2+1);
    }
};
class Node{
public:
    int value;
    Node* left=nullptr;
    Node* right=nullptr;
    Node(int v){

        this->value=v;
        this->left=nullptr;
        this->right=nullptr;
    }
};
class BT{

    Node* root;
    bool search(Node* temp,int n){

        if(temp== nullptr){
            return false;
        }
        if(temp->value==n){
            return true;
        }
        return search(temp->left,n)||search(temp->right,n);
    }
    void preorder(Node* temp){

        if(temp== nullptr){
            return;
        }
        cout<<temp->value<<" ";
        preorder(temp->left);
        preorder(temp->right);
    }
    void inorder(Node* temp){

        if(temp== nullptr){
            return;
        }
        inorder(temp->left);
        cout<<temp->value<<" ";
        inorder(temp->right);
    }
    void postorder(Node* temp){

        if(temp== nullptr){
            return;
        }
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->value<<" ";
    }
    void preorderNoRec(){

        stack<Node*> s;
        s.push(root);

        while(!s.empty()){
            Node* temp = s.top();
            s.pop();
            cout << temp->value << " ";
            if(temp->right != nullptr){
                s.push(temp->right);
            }
            if(temp->left != nullptr){
                s.push(temp->left);
            }
        }
    }
    void inorderNoRec(){

        if(root == nullptr) return;

        stack<Node*> s;
        Node* current = root;

        while(current != nullptr || !s.empty()){

            while(current != nullptr){
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            cout << current->value << " ";
            current = current->right;
        }
    }
    void postorderNoRec() {

        if (root == nullptr) return;
        stack<Node *> s1, s2;
        s1.push(root);
        while (!s1.empty()) {
            Node *temp = s1.top();
            s1.pop();
            s2.push(temp);
            if (temp->left != nullptr) {
                s1.push(temp->left);
            }
            if (temp->right != nullptr) {
                s1.push(temp->right);
            }
        }
        while(!s2.empty()){
            cout << s2.top()->value << " ";
            s2.pop();
        }
    }
public:
    BT(int v){

        root=new Node(v);
    }
    ~BT(){
        delete root;
    }
    void insert(int n){

        vector<Node*> v;
        v.push_back(0);
        v.push_back(root);
        for(int i=1;i>0;i++){

            if(v[i]->left==nullptr){

                v[i]->left=new Node(n);
                return;
            }
            if(v[i]->right==nullptr){

                v[i]->right=new Node(n);
                return;
            }
            v.push_back(v[i]->left);
            v.push_back(v[i]->right);
        }
    }
    void print(){

        preorder(root);
        cout<<endl;
        inorder(root);
        cout<<endl;
        postorder(root);
    }
    bool find(int n){

        return search(root,n);
    }
    void printNoRec(){

        preorderNoRec();
        cout<<endl;
        inorderNoRec();
        cout<<endl;
        postorderNoRec();
    }
    void BFSprint(){

        if(root== nullptr){return;}
        vector<Node*> v;
        v.push_back(0);
        v.push_back(root);
        for(int i=1;i>0;i++){

            if(v[i]==nullptr){

                return;
            }
            cout<<v[i]->value<<" ";
            v.push_back(v[i]->left);
            v.push_back(v[i]->right);
        }
    }
    int sum(int r=0){

        vector<Node*> v;
        v.push_back(0);
        v.push_back(root);
        for(int i=1;i>0;i++){

            if(v[i]==nullptr){

                return r;
            }
            r+=v[i]->value;
            v.push_back(v[i]->left);
            v.push_back(v[i]->right);
        }
    }
};
int main() {

    BT n(1);
    n.insert(2);
    n.insert(3);
    n.insert(4);
    n.insert(5);
    n.insert(6);
    n.insert(7);
    n.print();
    cout<<endl<<n.find(1)<<endl;
    n.printNoRec();
    cout<<endl;
    n.BFSprint();
    cout<<endl<<n.sum()<<endl;
    BSTvec a;
    a.insert(5);
    a.insert(4);
    a.insert(7);
    a.insert(1);
    a.insert(6);
    a.insert(8);
    a.insert(3);
    a.preorder();


    return 0;
}
