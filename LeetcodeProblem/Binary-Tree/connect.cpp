/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node *k=root;
        while(k!=nullptr) {
            Node *i=k;
            while(i!=nullptr) {
                if (i->left!=nullptr) i->left->next=i->right;
                if (i->right!=nullptr&&i->next!=nullptr) i->right->next=i->next->left;
                i=i->next;
            }
            k=k->left;
        }
        return root;
    }
};
