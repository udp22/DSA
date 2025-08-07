#include<bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    struct Node{
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int _key, int _val) {
        key = _key;
        val = _val;
        prev = nullptr;
        next = nullptr;
        }
    };

    unordered_map<int,Node*> ump;
    Node* head;
    Node* tail;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
        ump.clear();
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next=tail;
        tail->next=head;
    }
    
    void insertAfterhead(Node* node){
        Node* currentAfterhead=head->next;
        head->next=node;
        node->prev=head;
        node->next=currentAfterhead;
        currentAfterhead->prev=node;
    }

    void deleteNode(Node* node){
        Node* prevNode=node->prev;
        Node* nextNode=node->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }

    int get(int key) {
        auto it=ump.find(key);
        int value;
        if(it!=ump.end()){
            Node* node=it->second;
            value = node->val;
            deleteNode(node);
            insertAfterhead(node);
            return value;
        }
        else{
            return -1;
        }
    }
    
    void put(int key_, int value_) {
        auto it=ump.find(key_);
        if(it!=ump.end()){
            Node* node=it->second;
            node->val=value_;
            deleteNode(node);
            insertAfterhead(node);
        }
        else{
            if(ump.size()==cap){
                Node* node=tail->prev;
                ump.erase(node->key);
                deleteNode(node);
                
            }
            Node* node = new Node(key_,value_);
            insertAfterhead(node);
            ump[key_]=node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */