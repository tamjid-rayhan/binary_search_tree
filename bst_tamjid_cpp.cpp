#include<iostream>
using namespace std;


class tree_node{
    public:
        int key;
        tree_node *parent;
        tree_node *left;
        tree_node *right;
        int height;

        tree_node(int k, tree_node *p, tree_node *l, tree_node *r, int h){
            key = k;
            parent = p;
            left = l;
            right = r;
            height = h;
        }
};

class bst{
    public:
        tree_node *root = nullptr;

        bst(tree_node *r){
            root = r;
        }

        tree_node* find(tree_node* node, int k){
            if ((node == nullptr) || (k == node->key)){
                return node;
            }

            if (k < node->key){
                return find(node->left, k);
            }
            else{
                return find(node->right, k);
            }
        }

        void insert(tree_node *z){
            //tree_node *z =&tree_node(k, nullptr, nullptr, nullptr, 1);
            tree_node *y = nullptr;
            tree_node *x = this->root;
            while(x != nullptr){
                y = x;
                if (z->key < x->key){
                    x = x->left;
                }
                else{
                    x = x->right;
                }
            }
            z->parent = y;
            if (y==nullptr){
                this->root = z;
            }
            else if (z->key < y->key){
                y->left = z;
            }
            else{
                y->right = z;
            }
        }

};

int main(){
    tree_node node1(5, nullptr, nullptr, nullptr, 1);
    tree_node node2(9, nullptr, nullptr, nullptr, 1);

    cout << node1.key << "\n";
    cout << node2.key << "\n";

    bst first_bst(&node1);

    cout << first_bst.root->key << first_bst.root->height << "\n";

    tree_node* find_result = first_bst.find(first_bst.root, 5);

    cout << "find at root " << find_result->key << "\n";

    tree_node *z1 =new tree_node(10, nullptr, nullptr, nullptr, 1);
    tree_node *z2 =new tree_node(3, nullptr, nullptr, nullptr, 1);
    first_bst.insert(z1);
    first_bst.insert(z2);

    cout << "insert " << first_bst.root->height << "\n"; //expecting insert 1
    //cout << "insert 2 " << first_bst.find(first_bst.root, 2)->key << "\n"; //expecting insert 2 2
    cout <<first_bst.root->left->key << "\n";
    cout <<first_bst.root->right->key << "\n";
    auto new_res = first_bst.find(first_bst.root, 2);
    cout << "find executed" << "\n";
    cout << "insert 2 " << first_bst.find(first_bst.root, 3)->key << "\n"; //expecting insert 2 3
    cout << "insert 2 " << first_bst.find(first_bst.root, 10)->key << "\n"; //expecting insert 2 10

    return 0;
}





