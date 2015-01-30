#include <bits\stdc++.h>
const int maxn = 30000 + 10;
    int a[maxn];
    int c[maxn];
    int topi;
    int top2;

class MinStack {
public:

    MinStack() {
        memset(a, 0, sizeof(a));
        memset(c, 0, sizeof(c));
    }

    void push(int x) {
        a[++topi] = x;
        if (top2 == 0 || a[c[top2]] >= x) {
            c[++top2] = topi;
        }
    }

    void pop() {
        if (c[top2] == topi) top2--;
        topi--;
    }

    int top() {
        return a[topi];
    }

    int getMin() {
        return a[c[top2]];
    }
};

 MinStack MS;

 int main() {
     MS.push(512);
     MS.push(-1024);
     MS.push(-1024);
     MS.push(512);
     MS.pop();
    std::cout<<MS.getMin()<<std::endl;
     MS.pop();
    std::cout<<MS.getMin()<<std::endl;
     MS.pop();
     std::cout<<MS.getMin()<<std::endl;
 }
