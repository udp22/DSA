#include<bits/stdc++.h>
using namespace std;

class LFUCache {
public:
    struct Node{
        int key;
        int val,cnt;
        Node* prev;
        Node* next;
        Node(int _key,int _val){
            key=_key;
            val=_val;
            cnt=1;
            prev=nullptr;
            next=nullptr;
        }
    };

    struct List{
        int size;
        Node* head;
        Node* tail;
        List(){
            head=new Node(0,0);
            tail = new Node(0,0);
            head->next = tail;
            tail->next = head;
            size=0;
        }

        void addFront(Node* node){
            Node* temp=head->next;
            head->next=node;
            node->prev=head;
            node->next=temp;
            temp->prev=node;
            size++;
        }

        void removeNode(Node* node){
            Node* prevNode = node->prev;
            Node* nextNode = node->next;
            prevNode->next=nextNode;
            nextNode->prev=prevNode;
            size--;
        }

    }; 

    unordered_map<int,Node*>keyNode;
    unordered_map<int,List*>freq;

    int maxCapacity;
    int minFreq;
    int curSize;

    LFUCache(int capacity) {
        keyNode.clear();
        freq.clear();
        maxCapacity=capacity;
        minFreq=0;
        curSize=0;
    }

    void updateFreqListMap(Node* node){
        keyNode.erase(node->key);
        freq[node->cnt]->removeNode(node);
        if(node->cnt==minFreq && (freq[node->cnt]->size==0)){
            minFreq++;
        }

        List* nextHigherFreqList = new List();
        if(freq.find(node->cnt+1)!=freq.end()){
            nextHigherFreqList=freq[node->cnt+1];
        }
        node->cnt+=1;
        nextHigherFreqList->addFront(node);
        freq[node->cnt]=nextHigherFreqList;
        keyNode[node->key]=node;
    }
    
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end()){
            Node* node=keyNode[key];
            int val = node->val;
            updateFreqListMap(node);
            return val;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(maxCapacity==0){
            return;
        }
        if(keyNode.find(key)!=keyNode.end()){
            Node* node = keyNode[key];
            node->val=value;
            updateFreqListMap(node);
        }
        else{
            if(curSize==maxCapacity){
                List* list = freq[minFreq];
                keyNode.erase(list->tail->prev->key);
                freq[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            // new value has to be added who is not there previously
            minFreq=1;
            List* listFreq= new List();
            if(freq.find(minFreq)!=freq.end()){
                listFreq=freq[minFreq];
            }
            Node* node = new Node(key,value);
            listFreq->addFront(node);
            keyNode[key]=node;
            freq[minFreq]=listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */