 #include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertAtStart(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    void insertAtPosition(int pos, int val) {
        if (pos < 1) return;
        if (pos == 1) {
            insertAtStart(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 1; temp != NULL && i < pos - 1; i++)
            temp = temp->next;
        if (temp == NULL) return;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        cout << "List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void findNthFromEnd(int n) {
        Node* main = head;
        Node* ref = head;
        for (int i = 0; i < n; i++) {
            if (ref == NULL) {
                cout << "List is shorter than " << n << endl;
                return;
            }
            ref = ref->next;
        }
        while (ref != NULL) {
            main = main->next;
            ref = ref->next;
        }
        cout << "Nth node from end is: " << main->data << endl;
    }

    void createLoop() {
        if (head == NULL || head->next == NULL) return;
        Node* temp = head;
        Node* join = head->next;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = join;
    }

    void detectAndRemoveLoop() {
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (slow != fast) {
            cout << "No loop found\n";
            return;
        }
        slow = head;
        if (slow == fast) {
            while (fast->next != slow)
                fast = fast->next;
        } else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = NULL;
        cout << "Loop removed\n";
    }

    Node* reverseKGroup(Node* node, int k) {
        Node* prev = NULL;
        Node* curr = node;
        Node* next = NULL;
        int count = 0;
        Node* temp = node;
        for (int i = 0; i < k; i++) {
            if (temp == NULL) return node;
            temp = temp->next;
        }
        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (next != NULL)
            node->next = reverseKGroup(next, k);
        return prev;
    }

    void reverseInGroups(int k) {
        head = reverseKGroup(head, k);
        cout << "List reversed in groups of " << k << endl;
    }
};

int main() {
    LinkedList list;
    int choice, val, pos, n, k;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Start\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Display List\n";
        cout << "5. Find Nth Node from End\n";
        cout << "6. Reverse in Groups of K\n";
        cout << "7. Create Loop\n";
        cout << "8. Detect and Remove Loop\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            list.insertAtStart(val);
        } else if (choice == 2) {
            cout << "Enter value: ";
            cin >> val;
            list.insertAtEnd(val);
        } else if (choice == 3) {
            cout << "Enter position and value: ";
            cin >> pos >> val;
            list.insertAtPosition(pos, val);
        } else if (choice == 4) {
            list.display();
        } else if (choice == 5) {
            cout << "Enter n: ";
            cin >> n;
            list.findNthFromEnd(n);
        } else if (choice == 6) {
            cout << "Enter group size K: ";
            cin >> k;
            list.reverseInGroups(k);
        } else if (choice == 7) {
            list.createLoop();
            cout << "Loop created\n";
        } else if (choice == 8) {
            list.detectAndRemoveLoop();
        } else if (choice == 9) {
            cout << "Exiting...\n";
        } else {
            cout << "Invalid choice\n";
        }
    } while (choice != 9);

    return 0;
}
