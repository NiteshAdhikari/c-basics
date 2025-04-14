 #include <iostream>
using namespace std;

#define SIZE 10

class Queue {
    int arr[SIZE];
    int front, rear, count;

public:
    Queue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    void enqueue(int x) {
        if (count == SIZE) {
            cout << "Queue Overflow\n";
            return;
        }
        rear = (rear + 1) % SIZE;
        arr[rear] = x;
        count++;
    }

    void dequeue() {
        if (count == 0) {
            cout << "Queue Underflow\n";
            return;
        }
        front = (front + 1) % SIZE;
        count--;
    }

    void display() {
        if (count == 0) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % SIZE;
            cout << arr[index] << " ";
        }
        cout << endl;
    }

    void reverseFirstK(int k) {
        if (k > count || k <= 0) {
            cout << "Invalid K\n";
            return;
        }
        int temp[SIZE];
        for (int i = 0; i < k; i++) {
            int index = (front + i) % SIZE;
            temp[i] = arr[index];
        }
        for (int i = 0; i < k; i++) {
            int index = (front + i) % SIZE;
            arr[index] = temp[k - i - 1];
        }
        cout << "First " << k << " elements reversed\n";
    }

    void interleaveHalves() {
        if (count % 2 != 0) {
            cout << "Queue size must be even\n";
            return;
        }
        int temp[SIZE];
        for (int i = 0; i < count; i++) {
            int index = (front + i) % SIZE;
            temp[i] = arr[index];
        }

        int i = 0, j = count / 2;
        for (int k = 0; k < count; k++) {
            int index = (front + k) % SIZE;
            if (k % 2 == 0)
                arr[index] = temp[i++];
            else
                arr[index] = temp[j++];
        }
        cout << "Halves interleaved\n";
    }
};

int main() {
    Queue q;
    int choice, num, k;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Reverse First K Elements\n";
        cout << "5. Interleave Halves\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter number to enqueue: ";
            cin >> num;
            q.enqueue(num);
        } else if (choice == 2) {
            q.dequeue();
        } else if (choice == 3) {
            q.display();
        } else if (choice == 4) {
            cout << "Enter K: ";
            cin >> k;
            q.reverseFirstK(k);
        } else if (choice == 5) {
            q.interleaveHalves();
        } else if (choice == 6) {
            cout << "Exiting...\n";
        } else {
            cout << "Invalid choice\n";
        }
    } while (choice != 6);

    return 0;
}
