#include <iostream>
#include <vector>

using namespace std;

#define inf 1e9

struct Node {
    Node *previous;
    int value;
    Node() : previous(nullptr), value(0) {}
};

struct Stack {
    Node *head;
    int size_;
    Stack() : head(nullptr), size_(0) {}

    int top() {
        if (size_ > 0) {
            return head->value;
        } else {
            return -1;
        }
    }

    int size() {
        return size_;
    }

    void pop() {
        if (size_ > 0) {
            head = head->previous;
            size_--;
        }
    }

    void push(int value) {
        Node *new_ = new Node;
        new_->value = value;
        new_->previous = head;
        head = new_;
        size_++;
    }
};

int main() {
    int n;
    cin >> n;
    Stack st;
    vector<int> a(n + 2, -inf), ans(n, -1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    st.push(0);
    for (int i = 0; i <= n + 1; i++) {
        while (a[i] < a[st.top()]) {
            ans[st.top() - 1] = i;
            st.pop();
        }
        st.push(i);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}
