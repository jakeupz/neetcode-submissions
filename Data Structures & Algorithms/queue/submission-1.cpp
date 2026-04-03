class Node{
public:
    int val; 
    Node * next; 
    Node(int val): val(val), next(nullptr){}

};
class Deque {
public:
    
    Node * left = nullptr;
    Node * right = nullptr; 


    Deque() {}

    bool isEmpty() {
        return left == nullptr; 
    }

    void append(int value) {
        Node * butt = new Node(value); 
        if (right != nullptr){
            right->next = butt; 
            right = right->next;
        }else{ 
            left = right = butt; 
        }
    }

    void appendleft(int value) {
        Node * butt = new Node(value); 
        if (left != nullptr){
            butt->next = left;
            left = butt; 
        }else{ 
            left = right = butt; 
        }
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }

        int val = right->val;

        // If there is only one element
        if (left == right) {
            delete right;
            left = right = nullptr;
        } else {
            // Find the second-to-last node
            Node* current = left;
            while (current->next != right) {
                current = current->next;
            }
            delete right;
            right = current;
            right->next = nullptr;
        }

        return val;
    }

     int popleft() {
        if (isEmpty()) {
            return -1;
        }

        int val = left->val;
        Node* temp = left;

        left = left->next;

        if (left == nullptr) {
            right = nullptr;
        }

        delete temp;

        return val;
    }
};
