#include <bits/stdc++.h>

using namespace std;

class pqueue {
    private:
    pair<string, int> a[100000];
    int nHeap;

    public:
    pqueue() {
        nHeap = 0;
    }

    void add(string st, int val) {
        a[++nHeap] = make_pair(st, val);
        int cur = nHeap;
        while (cur / 2 >= 1 && a[cur].second < a[cur / 2].second) {
            swap(a[cur / 2], a[cur]);
            cur /= 2;
        }
    }

    string remove() {
        string res = a[1].first;
        swap(a[1], a[nHeap]);
        nHeap--;
        int cur = 2;
        while (cur <= nHeap) {
            if (cur + 1 <= nHeap && a[cur + 1].second < a[cur].second) cur++;
            if (a[cur].second < a[cur / 2].second) {
                swap(a[cur / 2], a[cur]);
            }
            cur = cur * 2;
        }
        return res;
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

