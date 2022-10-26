#include <iostream>
#include <vector>

using namespace std;

#define inf 1e9
#define int long long

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
signed main() {
    int n;
    cin >> n;
    Stack st1, st2;
    vector<int> a(n + 2, -inf), ans1(n, -1), ans2(n, -1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    st1.push(0);
    st2.push(n + 1);
    for (int i = 0; i <= n + 1; i++) {
        while (a[i] < a[st1.top()]) {
            ans1[st1.top() - 1] = i;
            st1.pop();
        }
        st1.push(i);
        while (a[n + 1 - i] < a[st2.top()]) {
            ans2[st2.top() - 1] = n + 1 - i;
            st2.pop();
        }
        st2.push(n + 1 - i);
    }
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s = max(s, a[i] * (ans1[i - 1] - ans2[i - 1] - 1));
    }
    cout << s << '\n';
    return 0;
}
