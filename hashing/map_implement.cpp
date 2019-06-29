#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

template <typename V>
class MapNode{
public:
    string key;
    V value;
    MapNode* next;

    MapNode(string key, V value){
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~MapNode(){
        delete next;
    }
};

template <typename V>
class ourmap {
    MapNode<V>** buckets;
    int count;
    int numBuckets;

    public:
    ourmap() {
        count=0;
        numBuckets = 5;
        buckets = new MapNode<V>*[numBuckets];

        for(int i=0; i<numBuckets; i++){
            buckets[i] = NULL;
        }
    }


    ~ourmap(){
        for(int i=0; i<numBuckets; i++){
            delete buckets[i];
        }

        delete [] buckets;
    }


    int size(){
        return count;
    }

    V getValue(string key){

    }

    private:
    int getBucketIndex(string key){
        int hashCode;
        int currCoeff = 1;
        for(int i=key.length()-1; i>=0; i--){
            hashCode += key[i]*currCoeff;
            hashCode = hashCode%numBuckets;
            currCoeff *= 37;
            currCoeff = currCoeff % numBuckets;
        }

        return hashCode%numBuckets;
    }

    void rehash(){
        MapNode<V> * temp = buckets;
        buckets = new MapNode<V>*[2*numBuckets];
        for(int i=0; i<2*numBuckets; i++){
            buckets[i] = NULL;
        }
        int oldBucketCount = numBuckets;
        numBuckets *= 2;
        count = 0;

        for(int i=0; i< oldBucketCount; i++){
            MapNode<V> * head = temp[i];
            while(head!=NULL){
                string key = head ->key;
                V value = head ->value;
                insert(key,value);
                head = head->next;
            }
        }

        for(int i=0; i<oldBucketCount; i++){
            MapNode<V>* head = temp[i];
            delete head;
        }

        delete [] temp;
    }

    public:
    void insert(string key, V value) {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while(head!=NULL){
            if(head->key == key){
                head->value = value;
                return;
            }
            head = head ->next;
        }

        head = buckets[bucketIndex];
        MapNode<V>* node = new MapNode<V> (key,value);
        buckets[bucketIndex] = node;
        count++;
        double loadFactor = (1.0 * count)/numBuckets;
        if(loadFactor > 0.7){
            rehash();
        }
    }

    V remove(string key){

    }
};


int main() {

    return 0;
}