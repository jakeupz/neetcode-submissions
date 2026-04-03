class Node {
public:
    int val;
    Node* next;

    Node(int val) : val(val), next(nullptr) {}
    Node(int val, Node* next) : val(val), next(next) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    int get(int index) {
        Node* curr = head;
        int i = 0;

        while (curr != nullptr) {
            if (i == index) {
                return curr->val;
            }
            i++;
            curr = curr->next;
        }
        return -1; // Return -1 if index is out of range
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertTail(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool remove(int index) {
        if (index < 0 || head == nullptr) return false;

        Node* curr = head;
        if (index == 0) {
            head = head->next;
            if (head == nullptr) {
                tail = nullptr;
            }
            delete curr;
            return true;
        }

        Node* prev = nullptr;
        int i = 0;
        while (i < index && curr != nullptr) {
            prev = curr;
            curr = curr->next;
            i++;
        }

        if (curr == nullptr) return false; // Index out of range

        prev->next = curr->next;
        if (curr == tail) {
            tail = prev;
        }
        delete curr;
        return true;
    }

    vector<int> getValues() {
        vector<int> bruh;
        Node* curr = head;
        while (curr != nullptr) {
            bruh.push_back(curr->val);
            curr = curr->next;
        }
        return bruh;
    }
};