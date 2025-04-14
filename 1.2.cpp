 #include <iostream>
using namespace std;

#define SIZE 10

class Stack {
    int arr[SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == SIZE - 1) {
            cout << "Stack is full\n";
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        top--;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void findMiddle() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        int mid = top / 2;
        cout << "Middle element: " << arr[mid] << endl;
    }

    void reverseBottomHalf() {
        if (top < 1) {
            cout << "Not enough elements\n";
            return;
        }
        int mid = top / 2;
        for (int i = 0, j = mid; i < j; i++, j--) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        cout << "Bottom half reversed\n";
    }
};

int main() {
    Stack s;
    int choice, num;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display Stack\n";
        cout << "4. Find Middle Element\n";
        cout << "5. Reverse Bottom Half\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter number to push: ";
            cin >> num;
            s.push(num);
        } else if (choice == 2) {
            s.pop();
        } else if (choice == 3) {
            s.display();
        } else if (choice == 4) {
            s.findMiddle();
        } else if (choice == 5) {
            s.reverseBottomHalf();
        } else if (choice == 6) {
            cout << "Exiting...\n";
        } else {
            cout << "Invalid choice\n";
        }

    } while (choice != 6);

    return 0;
}
