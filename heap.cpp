#include <bits/stdc++.h>

using namespace std;

struct node {
    node* prev;
    node* next;
    int value;
    string key;
};
class pqueue {
    private:
    node* head;
    node* tail;

    void link(node* left, node* right) {
        left->next = right;
        right->prev = left;
    }

    public:
    pqueue() {
        head = new node();
        tail = new node();
        link(head, tail);
    }

    void add(string st, int val) {
        node* temp = new node();
        temp->key = st;
        temp->value = val;
        link(temp, head->next);
        link(head, temp);
    }

    string remove() {
        node* temp = head->next;
        node* res = NULL;
        while (temp != tail) {
            if (res == NULL || temp->value < res->value) {
                res = temp;
            }
            temp = temp->next;
        }
        string result = res->key;
        link(res->prev, res->next);
        delete(res);
        return result;
    }
};

pqueue pq;
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    pq.add("X", 10);
    pq.add("Y", 1);
    pq.add("Z", 3);
    cout<<pq.remove()<<endl;
    cout<<pq.remove()<<endl;
    cout<<pq.remove()<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

