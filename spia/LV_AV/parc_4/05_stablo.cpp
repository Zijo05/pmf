#include <iostream>
#include <queue>

template <typename T>
class Tree {
    class Node {
    public:
        T m_value;
        Node* m_child_l;
        Node* m_child_r;

        Node() : m_child_l(nullptr), m_child_r(nullptr) {}
        ~Node() { std::cout << "Deleting node: " << m_value << std::endl; }
        Node(T a_value) : m_value(a_value), m_child_l(nullptr), m_child_r(nullptr) {}
    };

    Node* m_root;

    void preorder_rec(Node* n) {
        if(n == nullptr)
            return;
        
        std::cout << n->m_value << " ";
        preorder_rec(n->m_child_l);
        preorder_rec(n->m_child_r);
    }

    void inorder_rec(Node* n) {
        if(n == nullptr)
            return;
        
        inorder_rec(n->m_child_l);
        std::cout << n->m_value << " ";
        inorder_rec(n->m_child_r);
    }

    void postorder_rec(Node* n) {
        if(n == nullptr)
            return;
        
        postorder_rec(n->m_child_l);
        postorder_rec(n->m_child_r);
        std::cout << n->m_value << " ";
    }

    void clear_rec(Node* n) {
        if (n == nullptr)
            return;
        clear_rec(n->m_child_l);
        clear_rec(n->m_child_r);
        delete n;
    }

    void depth_print_rec(Node* ptr, int current_depth, int wanted_depth) {
        if(ptr == nullptr) return;
        if(current_depth == wanted_depth) {
            std::cout << ptr->m_value << " ";
            return;
        }
        depth_print_rec(ptr->m_child_l, current_depth + 1, wanted_depth);
        depth_print_rec(ptr->m_child_r, current_depth + 1, wanted_depth);
    }

    int value_depth_rec(Node* ptr, int current_depth, int a_value) {
        if(ptr == nullptr) 
            return -1;
        
        if(ptr->m_value == a_value)
            return current_depth;
        
        if(a_value < ptr->m_value) return value_depth_rec(ptr->m_child_l, current_depth + 1, a_value);
        else return value_depth_rec(ptr->m_child_r, current_depth + 1, a_value);

    }

    int height_rec(Node* n) {
        if (n == nullptr) return 0;
        return std::max(height_rec(n->m_child_l), height_rec(n->m_child_r)) + 1;
    }

public:
    Tree() : m_root(nullptr) {}
    Tree(Node* a_root) : m_root(a_root) {}
    ~Tree() {
        // TODO
    }

    /* # Too complicated
    void append(T a_value) {
        Node* new_node = new Node(a_value);

        if (m_root == nullptr) m_root = new_node;
        else {
            Node* ptr = m_root;
            while(true) {
                if(!(ptr->m_child_l == nullptr) && new_node->m_value < ptr->m_value)
                    ptr = ptr->m_child_l;
                if(!(ptr->m_child_r == nullptr) && new_node->m_value >= ptr->m_value)
                    ptr = ptr->m_child_r;
                else{
                    if(new_node->m_value < ptr->m_value)
                        ptr->m_child_l = new_node;
                    else
                        ptr->m_child_r = new_node;
                    break;
                }
            }
        }
    }*/

    void append(T a_value){
        Node* new_node = new Node(a_value);

        if (m_root == nullptr) { 
            m_root = new_node;
            return;
        }

        Node* ptr = m_root;
        while(true) {
            if (new_node->m_value < ptr->m_value){
                if(ptr->m_child_l == nullptr){
                    ptr->m_child_l = new_node;
                    return;
                }
                ptr = ptr->m_child_l;
            } else {
                if(ptr->m_child_r == nullptr){
                    ptr->m_child_r = new_node;
                    return;
                }
                ptr = ptr->m_child_r;
            }
        }
    }

    void preorder() {
        if (m_root == nullptr)
            throw std::runtime_error("The tree is empty!");
        preorder_rec(m_root);
    }

    void inorder() {
        if (m_root == nullptr)
            throw std::runtime_error("The tree is empty!");
        inorder_rec(m_root);
    }

    void postorder() {
        if (m_root == nullptr)
            throw std::runtime_error("The tree is empty!");
        postorder_rec(m_root);
    }

    /* # Ovaj ne dodaje novi red poslije svakog levela
    void levelorder() {
        if (m_root == nullptr)
            throw std::runtime_error("The tree is empty!");
        
        std::queue<Node*> q;
        q.push(m_root);

        while(!q.empty()) {
            Node* ptr = q.front();
            q.pop();

            std::cout << ptr->m_value << " ";

            if (ptr->m_child_l != nullptr) q.push(ptr->m_child_l);
            if (ptr->m_child_r != nullptr) q.push(ptr->m_child_r);
        }
    }*/

    void levelorder(){
        if (m_root == nullptr)
            throw std::runtime_error("The tree is empty!");

        std::queue<Node*> q;
        q.push(m_root);

        while(!q.empty()) {
            int level_size = q.size();

            for(int i(0); i < level_size; i++){
                Node* ptr = q.front();
                q.pop();
    
                std::cout << ptr->m_value << " ";
    
                if (ptr->m_child_l != nullptr) q.push(ptr->m_child_l);
                if (ptr->m_child_r != nullptr) q.push(ptr->m_child_r);
            }
            std::cout << std::endl;
        }
    }

    void clear() {
        if (m_root == nullptr)
            return;
        clear_rec(m_root);
        m_root = nullptr;
    }

    void depth_print(int depth){
        if(m_root == nullptr)
            return;
        depth_print_rec(m_root, 0, depth);
    }

    int value_depth(T a_value) { return value_depth_rec(m_root, 0, a_value); }

    int height() {
        return height_rec(m_root);
    }
};

int main() {

    Tree<int> t;
    t.append(5);
    t.append(7);
    t.append(1);
    t.append(3);
    t.append(2);
    t.append(4);
    t.append(6);
    t.append(8);
    t.append(9);
    t.append(10);

    t.preorder();
    std::cout << std::endl;
    t.inorder();
    std::cout << std::endl;
    t.postorder();
    std::cout << std::endl << "Level order: " << std::endl;
    t.levelorder();
    std::cout << std::endl;
    std::cout << std::endl;

    t.depth_print(6);
    t.depth_print(0);
    std::cout << std::endl;
    t.depth_print(1);
    std::cout << std::endl;
    t.depth_print(2);
    std::cout << std::endl;
    t.depth_print(3);
    std::cout << std::endl;
    t.depth_print(4);
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Tree height is " << t.height();
    std::cout << "\nDepth of 4 is " << t.value_depth(4);
    std::cout << "\nDepth of 6 is " << t.value_depth(6);

    return 0;
}