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


        tree_node* tree_minimum(tree_node* node){
            while (node->left != nullptr){
                node = node->left;
            }
            return node;
        }


        tree_node* tree_maximum(tree_node* node){
            while(node->right != nullptr){
                node = node->right;
            }
            return node;
        }


        tree_node* successor(tree_node* node){
            if (node->right != nullptr){
                return tree_minimum(node->right);
            }
            tree_node* y = node->parent;
            while(y != nullptr and y->right == node){
                node = y;
                y = y->parent;
            }
            return y;
        }

        void transplant(tree_node* root, tree_node* replaced, tree_node* replacer){
            if (replaced->parent == nullptr){
                root = replacer;
            }
            else if (replaced->parent->left = replaced){
                replaced->parent->left = replacer;
            }
            else{
                replaced->parent->right = replacer;
            }

            if (replacer != nullptr){
                replacer->parent = replaced->parent;
            }
        }

        void tree_delete(tree_node* root, tree_node* z){
            if (z->left == nullptr){
                transplant(root, z, z->right);
            }
            else if(z->right == nullptr){
                transplant(root, z, z->left);
            }
            else{
                tree_node* y = tree_minimum(z->right);
                if (y->parent != z){
                    transplant(root, y, y->right);
                    y->right = z->right;
                    y->right->parent = y;
                }
                transplant(root, z, y);
                y->left = z->left;
                y->left->parent = y;
            }
        }

        void in_order_traversal(tree_node* node){
            if (node != nullptr){
                in_order_traversal(node->left);
                cout << node->key << " ";
                in_order_traversal(node->right);
            }
        }
};

int main(){
    tree_node node1(15, nullptr, nullptr, nullptr, 1);
    tree_node node2(9, nullptr, nullptr, nullptr, 1);

    cout << node1.key << "\n";
    cout << node2.key << "\n";

    bst first_bst(&node1);

    cout << first_bst.root->key << first_bst.root->height << "\n";

    tree_node* find_result = first_bst.find(first_bst.root, 15);

    cout << "find at root " << find_result->key << "\n";

    //tree_node *z1 =new tree_node(6, nullptr, nullptr, nullptr, 1);
    //tree_node *z2 =new tree_node(18, nullptr, nullptr, nullptr, 1);
    tree_node z1(6, nullptr, nullptr, nullptr, 1);
    tree_node z2(18, nullptr, nullptr, nullptr, 1);
    tree_node z3(3, nullptr, nullptr, nullptr, 1);
    tree_node z4(7, nullptr, nullptr, nullptr, 1);
    tree_node z5(17, nullptr, nullptr, nullptr, 1);
    tree_node z6(20, nullptr, nullptr, nullptr, 1);
    tree_node z7(2, nullptr, nullptr, nullptr, 1);
    tree_node z9(4, nullptr, nullptr, nullptr, 1);
    tree_node z10(13, nullptr, nullptr, nullptr, 1);
    tree_node z11(9, nullptr, nullptr, nullptr, 1);
    first_bst.insert(&z1);
    first_bst.insert(&z2);
    first_bst.insert(&z3);
    first_bst.insert(&z4);
    first_bst.insert(&z5);
    first_bst.insert(&z6);
    first_bst.insert(&z7);
    first_bst.insert(&z9);
    first_bst.insert(&z10);
    first_bst.insert(&z11);

    cout << "insert " << first_bst.root->height << "\n"; //expecting insert 1
    //cout << "insert 2 " << first_bst.find(first_bst.root, 2)->key << "\n"; //expecting insert 2 2
    cout <<first_bst.root->left->key << "\n";
    cout <<first_bst.root->right->key << "\n";
    auto new_res = first_bst.find(first_bst.root, 6);
    cout << "find executed" << "\n";
    cout << "insert 2 " << first_bst.find(first_bst.root, 6)->key << "\n"; //expecting insert 2 3
    cout << "insert 2 " << first_bst.find(first_bst.root, 18)->key << "\n"; //expecting insert 2 10

    cout << "minimum " << first_bst.tree_minimum(first_bst.root)->key << "\n"; //expecting minimum 2
    cout << "maximum " << first_bst.tree_maximum(first_bst.root)->key << "\n"; //expecting maximum 20
    cout << "successor " << first_bst.successor(first_bst.find(first_bst.root, 13))->key << "\n"; //expecting successor 15

    first_bst.in_order_traversal(first_bst.root);
    cout<<"\n";
    first_bst.tree_delete(first_bst.root, first_bst.find(first_bst.root, 6));
    first_bst.in_order_traversal(first_bst.root);
    cout<<"\n";
    return 0;
}





