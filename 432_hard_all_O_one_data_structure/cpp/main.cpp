#include "../../include/leetcode.hpp"

class AllOne {
    struct Node{
        unordered_set<string> keys;
        int cnt;
        Node *prev;
        Node *next;
        Node(): keys({}), cnt(1), prev(nullptr), next(nullptr){};
    };

    unordered_map<string, Node *> keyCnt;
    Node *head, *tail;

    void insert(Node *prev, Node *node) {
        node->next = prev->next;
        node->prev = prev;
        prev->next = node;
        node->next->prev = node;
    }

    void check_empty(Node *node) {
        if (node->keys.size() == 0) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
        }
    }
public:
    AllOne() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;

        head->cnt = INT_MIN;
        tail->cnt = INT_MAX;
    }

    ~AllOne() {
        Node *p;
        Node *fp;
        p = head->next;
        while(p != tail) {
            fp = p;
            p = p->next;
            delete fp;
        }
        delete head;
        delete tail;
    }
    
    void inc(string key) {
        if (keyCnt.find(key) == keyCnt.end()) {
            if (head->next->cnt > 1) {
                Node *newNode = new Node();
                newNode->keys.insert(key);
                // insert after head
                insert(head, newNode);
                keyCnt[key] = newNode;
            } else {
                // cnt must be 1
                head->next->keys.insert(key);
                keyCnt[key] = head->next;
            }
        } else {
            Node *node = keyCnt[key];
            if (node->cnt + 1 == node->next->cnt) {
                // colease
                node->keys.erase(key);
                node->next->keys.insert(key);
                keyCnt[key] = node->next;

                check_empty(node);
            } else {
                // insert a new node;
                Node *newNode = new Node();
                newNode->cnt = node->cnt + 1;
                newNode->keys.insert(key);
                insert(node, newNode);

                node->keys.erase(key);
                check_empty(node);
                keyCnt[key] = newNode;
            }
        }
    }

    void dec(string key) {
        Node *node = keyCnt[key];
        if (node->cnt == 1) {
            node->keys.erase(key);
            keyCnt.erase(key);
            check_empty(node);
            return;
        }
        if (node->cnt - 1 == node->prev->cnt) {
            // colease
            node->keys.erase(key);
            node->prev->keys.insert(key);
            keyCnt[key] = node->prev;
            check_empty(node);
        } else {
            // insert new node
            Node *newNode = new Node();
            newNode->cnt = node->cnt - 1;
            newNode->keys.insert(key);
            insert(node->prev, newNode);
            node->keys.erase(key);
            keyCnt[key] = newNode;
            check_empty(node);
        }
    }

    string getMaxKey() {
        if (tail->prev != head)
            return *tail->prev->keys.begin();
        else
            return "";
    }

    string getMinKey() {
        if (head->next != tail)
            return *head->next->keys.begin();
        else
            return "";
    }

    void dump(int epoch) {
        Node *p;
        p = head->next;

        cout << "Epoch: " << epoch << endl;
        while(p != tail) {
            cout << "{ cnt: " << p->cnt << ", ";
            fmt::print("keys: {}", p->keys);
            cout << "}" << endl;
            p = p->next;
        }
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

int main() {
    AllOne allone;
    allone.inc("a");
    allone.dump(1);
    allone.inc("b");
    allone.dump(2);
    allone.inc("b");
    allone.dump(3);
    allone.inc("c");
    allone.dump(4);
    allone.inc("c");
    allone.dump(5);
    allone.inc("c");
    allone.dump(6);
    allone.dec("b");
    allone.dump(7);
    allone.dec("b");
    allone.dump(8);
    cout << allone.getMinKey() << endl;
    cout << allone.getMaxKey() << endl;
    allone.dec("a");
    allone.dump(9);
    cout << allone.getMinKey() << endl;
}
