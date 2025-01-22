#include<iostream>
using namespace std;
#include<queue>
class node{
    public:
    int data;
    node *left;
    node *right;

    node (int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
class bst{
    node *root;
    public:
    bst(){
        root=NULL;
    }

    void insert(int val){
        node *n=new node(val);
        if(root==NULL){
            root=n;
            return;
        }
        node *p=NULL;
        node *c=root;
        while(c!=NULL){
            p=c;

            if(val < c->data){
                c=c->left;
            }else if(val > c->data){
                c=c->right;
            }
            else {
                delete n;
                return;
            }
        }

        if(val < p->data){
            
            p->left=n;
            return;

        }else{
            p->right=n;
            return;

        }
    }

    void insert2(node *&curr,int val){
        if(curr==NULL){
            node *n=new node(val);
            curr=n;
            return;

        }
        if(val==curr->data){
            return;
        }

        if(val < curr->data){

            if(curr->left==NULL){
                node *n=new node(val);
                curr->left=n;
                return;
            }else{
                insert2(curr->left,val);
            }

        }else{

            if(curr->right!=NULL){
insert2(curr->right,val);


            }else{
node *n=new node(val);
curr->right=n;
return;


            }






        }
    }

    node *getroot(){
        return root;
    }

    void preorder(node *root){
        if(root==NULL){
            return;

        }

        cout <<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(node *root){
        if(root==NULL){
            return;
        }


        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
// all those nodes that have no child this func returns its sum recursively 
    int sum_leaf_nodes(node *root){
        if(root==NULL){
            return -1;
        }

        /*if(root->left==NULL && root->right==NULL){
            return root->data;
        }*/

        return (root->left==NULL && root->right==NULL?root->data:0)+sum_leaf_nodes(root->left)+sum_leaf_nodes(root->right);
    }
/// retrun sum of all nodes
int sum(node *root){
    if(root==NULL){
        return 0;
    }

    return root->data +sum(root->left) +  sum(root->right);
}
// recursively checks if a key existss in bst 
bool search(node *root,int val){
    if(root==NULL){
        return false;
    }

if(val==root->data){
    return true;
}
if(val < root->data){
    return search(root->left,val);
}

else{

    return search(root->right,val);
}
   // return search(root->left,val) || search(root->right,val);
}
//cout total nos of even noodes recursively 
int count_even(node *root){
    if(root==NULL){
        return 0;
    }

    
    return (root->data % 2==0?1:0)+count_even(root->left)+count_even(root->right);
}
// count no of nodes greater then specififc target
int count_greater_than(node *root,int val){

    if(root==NULL){
        return 0;
    }



    return (root->data > val ?1:0)+count_greater_than(root->left,val)+count_greater_than(root->right,val);
}
//finds and returns sum of nodes with odd values
int sum_odd_node(node *root){
    if(root==NULL){
        return 0;
    }

    return (root->data % 2!=0?root->data:0) + sum_odd_node(root->left)+sum_odd_node(root->right);
}
// imp 
// finds sum of nodes within min and max range
int sum_range(node *root,int min,int max){
    if(root==NULL){
        return 0;
    }

   

    return (root->data >=min && root->data <=max?root->data:0)+sum_range(root->left,min,max)+sum_range(root->right,min,max);
}

int count_non_leaf(node *root){
    if(root==NULL){
        return 0;
    }

    return (root->left!=NULL || root->right!=NULL?1:0)+count_non_leaf(root->left)+count_non_leaf(root->right);
}
//counts nodes whose both childs are even 
int count_even_child(node *root){
    if(root==NULL){
        return 0;
    }

    if(root->left->data %2==0 && root->right->data %2==0){
        return 1;
    }else{
        return 0;
    }

    return count_even_child(root) + count_even_child(root->left)+count_even_child(root->right);}

//finds the node closest to target
int closest(node *root,int target){

    if(root==NULL){
        return -1;

    }
    int closest=root->data;
node *c=root;
    while(c!=NULL){

        if((target - c->data )*(target - c->data) < (target-closest) * (target- closest)){
            closest=c->data;
        }

        if(target < c->data){
            c=c->left;
        }else if(target > c->data){
            c=c->right;
        }else{

            break;
        }
    }

    return closest;
}

int count_nodes_divisible(node *root,int k){
    if(root==NULL){
        return 0;
    }

    return (root->data % k==0?1:0)+count_nodes_divisible(root->left,k)+count_nodes_divisible(root->right,k);
}

int min(node *root){
    if(root==NULL){
        return -1;
    }

 return (root->left==NULL ?root->data:min(root->left));
}
int max(node *root){
    if(root==NULL){
        return -1;
    }

    if(root->right==NULL){
        return root->data;
    }

    return max(root->right);
}
bool isbst(node *root,int min,int max){
    if(root==NULL){
        return true;
    }

    if(root->data <=min || root->data >=max){
        return false;
    }

    return isbst(root->left,min,root->data) || isbst(root->right,root->data,max);
}

int sum_lvlorder(node *root){
if(root==NULL){
    return 0;
}
 queue<node *> q;
        int sum=0;
        q.push(root);

        while (!q.empty()) {
            node *n = q.front();
            q.pop();

        sum+=n->data;

            if (n->left != NULL) {
                q.push(n->left);
            }

            if (n->right != NULL) {
                q.push(n->right);
            }
        }
        return sum;
    }
int total_non_leaf_lvlorder(node *root){
if(root==NULL){
    return 0;
}
 queue<node *> q;
        int count=0;
        q.push(root);

        while (!q.empty()) {
            node *n = q.front();
            q.pop();

        if(n->left!=NULL || n->right !=NULL){
            count++;
        }

            if (n->left != NULL) {
                q.push(n->left);
            }

            if (n->right != NULL) {
                q.push(n->right);
            }
        }
        return count;
    }


int  max_levelorder(node *root) {
        if (root == NULL) {
            return -1;
        }

        // Use STL queue for level order traversal
        queue<node *> q;
        int max=root->data;
        q.push(root);

        while (!q.empty()) {
            node *n = q.front();
            q.pop();

            if(n->data > max){
                max=n->data;
            }

            if (n->left != NULL) {
                q.push(n->left);
            }

            if (n->right != NULL) {
                q.push(n->right);
            }
        }
        return max;
    }
   //remember depth is a property of a node not tree depth of any node means level at which is stands (how deep)
   //depth of a particular node is its distance of levels or edges from root node

int depth(node *root,node *target,int curr=0){
    if(root==NULL){
        return -1;  // empty tree has no targert found
    }

    if(root==target){

        return curr;   //targert is found at root suince depth of root is 0
    }

    int left=depth(root->left,target,curr+1);

    if(curr!=-1){

        return left;
    }

    return depth(root->right,target,curr+1);
}

bool isbalanced(node *root){
    if( root ==NULL){
        return true;    // kuch hai hi ni jisko check kry to yai empty tree bst hoga
    }

    int lefth=height(root->left);
    int righth=height(root->right);

    if(lefth-righth > 1|| righth-lefth >1){
        return false;
    }

    return isbalanced(root->left) && isbalanced(root->right);
}

bool issymmetric(node *root){      //symmetric is a tree which is a mirrot of itself
    if(root==NULL){
        return true;
    }

    return ismirror(root->left,root->right);
}



    int height(node *root){ // max no of edges
        if(root==NULL){
     return -1;     // empty tree so height cant exist

}

        int lefth=height(root->left);
        int righth=height(root->right);

        return 1+max(lefth,righth);
    }

    int max(int a,int b){
        if(a>b){
            return a;
        }else{
            return b;
        }
    }

int count_tot_node(node *root){
    if(root==nullptr){
        return 0;
    }

   

    return 1+ count_tot_node(root->left)+count_tot_node(root->right);
}


int no_leaf(node *root){
    if(root==NULL){
        return 0;
    }




    return (root->left==NULL && root->right==NULL ? 1:0)+no_leaf(root->left)+no_leaf(root->right);
}

    


    bool isComplete() {
        if (root == nullptr) return true;

        queue<node*> q;
        q.push(root);

        bool nullNodeFound = false;

        while (!q.empty()) {
            node* currentNode = q.front();
            q.pop();

            if (currentNode == nullptr) {
                nullNodeFound = true;
            } else {
                if (nullNodeFound) {
                    // If we find a non-null node after a null node, it's not complete
                    return false;
                }
                q.push(currentNode->left);
                q.push(currentNode->right);
            }
        }

        return true;
    }
bool issame(node *s,node *t){  // checks if 2 trees are same
    if(s==nullptr && t==nullptr){   //if both are null nothing to check so it is same
        return true;
    }

    if(s==nullptr || t==nullptr){   // if 1 tree is null and other is non null so cant be same 
        return false;
    }

    return (s->data==t->data ? true:false) && issame(s->left,t->left) && issame(s->right,t->right);
}


bool ismirror(node *s,node *t){// checks if 2 trees are mirror of each other
    if(s==nullptr && t==nullptr){
        return true;       // if both null so by default mirror
    }

    if(s==nullptr || t==nullptr){
        return false;     //if one is null and other is not so not mirrror
    }

    return (s->data==t->data ? true:false) && ismirror(s->left,t->right) && ismirror(s->right,t->left);  //left subtree of tree 1 and right subtree of tree 2 should be same

}

node *lca(node *root,int p,int q){
    if(root==NULL || root->data==p || root->data==q){
        return root;
    }

    node *left=lca(root->left,p,q);
    node  *right=lca(root->right,p,q);

// if both left lca and right lca are not null so return their root
    if(left!=NULL && right!=NULL){
        return root;
    }
// other wise return non null lca
    return left!=nullptr ? left:right;
}
   
    bool ismirror(node *s,node *t){
          if(s==NULL && t==NULL){

return true;

        }
        if(s==NULL || t==NULL){
            return true;
        }

        return (s->data==t->data?true:false) && ismirror(s->left,t->right)&&ismirror(s->right,t->left);
    }

    bool issymetric(node *root){  // mirror of itself
        if(root==NULL){
return true;
        }

        return ismirror(root->left,root->right);
    }
};
int main(){

bst t;

t.insert(16);
t.insert(12);
t.insert(18);
t.insert(1);

node *root=t.getroot();
t.preorder(root);
cout<<"sum is "<<t.sum_leaf_nodes(root)<<endl;
cout<<"total sum of bst is "<<t.sum(root)<<endl;

if(t.search(root,11)){
    cout<<"Val is found "<<endl;
}else{
    cout<<"it doesnt exists "<<endl;
}

cout<<"total even nodes are "<<t.count_even(root)<<endl;

cout<<"total nodes greater than val are "<<t.count_greater_than(root,14)<<endl;
cout<<"sum of odd nodes are "<<t.sum_odd_node(root)<<endl;


cout<<"sum of nodes within range are "<<t.sum_range(root,12,19)<<endl;

cout <<"total non leaf nodes are "<<t.count_non_leaf(root)<<endl;
cout<<"total nodes with even child are "<<t.count_even_child(root)<<endl;

cout<<"closest value to 13 is : "<<t.closest(root,13)<<endl;

cout<<"total no of nodes divisible by 3 is: "<<t.count_nodes_divisible(root,3)<<endl;
cout<<"minimum no here is "<<t.min(root)<<endl;
cout<<"maximum no here is "<<t.max(root)<<endl;

if(t.isbst(root,-100000,100000)){
    cout<<"given tree is bst "<<endl;
}else{
    cout<<"given tree is not bst "<<endl;
}

cout<<"mamximum in given tree is "<<t.max_levelorder(root)<<endl;

cout<<"sum using level order traversal is "<<t.sum_lvlorder(root)<<endl;
cout<<"total no of non leaf nodes using lvl order traversal is "<<t.total_non_leaf_lvlorder(root)<<endl;
cout<<"height of this tree is "<<t.height(root)<<endl;
cout<<"depth of node with val 12 is "<<t.depth(root,root->left->left,0)<<endl;

if(t.isbalanced(root)){
    cout<<"given bst is balance "<<endl;
}else{
    cout<<"given bst is not balanced "<<endl;
}

if(t.isComplete()){
    cout<<"given bst is complete"<<endl;
}else{
    cout<<"given bst is not complete "<<endl;
}

cout<<"total nos of nodes in this bst is "<<t.count_tot_node(root)<<endl;

cout<<"total no of lead nodes are "<<t.no_leaf(root)<<endl;


}

