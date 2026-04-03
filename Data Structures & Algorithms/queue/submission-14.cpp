class Node { 
    public:
        int val;
        Node * next;

        Node(int val) : val(val), next(nullptr) {}

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
        Node * newNode = new Node(value);

        if (right != nullptr){
            right->next = newNode;
            right = right->next;  
        }
        else{
            left = right = newNode; 
        }
    }

    void appendleft(int value) {
        Node * newNode = new Node(value);

        if(left != nullptr){
            newNode->next = left;
            left = newNode;  
        }else{
            left = right = newNode; 
        }
    }

    int pop() {
       if(!isEmpty()){
        int values = right->val; 
        if (left != right){
            Node * current = left; 
            while(current->next != right){
                current = current->next; 
            }
             delete right; 
             right = current;
             right->next = nullptr; 
        } 
        else{
             delete right;
             left = right = nullptr;    
            }
            return values; 
       } 
       return -1; 
    }

   int popleft() {
    // If the queue is empty, return -1
    if (isEmpty()) {
        return -1;
    }

    // Store the value to return
    int values = left->val;

    // Move the left pointer to the next node
    left = left->next;

    // If the queue is now empty after popping, set right to nullptr as well
    if (left == nullptr) {
        right = nullptr;
    }

    return values;
}


};
