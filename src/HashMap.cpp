#include "HashMap.hpp"

template<typename K, typename V>
HashMap<K, V>::HashMap(): bucketCount(8), elementCount(0){
    buckets = new Node*[bucketCount];
    for(size_t i=0; i<bucketCount; ++i){
        buckets[i] = nullptr;
    }
}

template<typename K, typename V>
HashMap<K, V>:: ~HashMap(){
    clear();
    delete [] buckets;
}

template<typename K, typename V>
HashMap<K, V>::HashMap(const HashMap& other){
    buckets = nullptr;
    bucketCount = 0;
    elementCount = 0;

    copyFrom(other);
}

template<typename K, typename V>
HashMap<K, V>& HashMap<K, V>::operator=(const HashMap& other){
    if(this != &other){
        clear();
        delete[] buckets;
        buckets=  nullptr;
        bucketCount=0;
        elementCount=0;

        copyFrom(other);
    }
    return *this;
}

template<typename K, typename V>
void HashMap<K, V>::copyFrom(const HashMap& other){
    bucketCount = other.bucketCount;
    elementCount = 0;

    buckets = new Node*[bucketCount];
    for(size_t i = 0; i < bucketCount; ++i){
        buckets[i] = nullptr;
    }

    for(size_t i=0; i<bucketCount; ++i){
        Node* current = other.buckets[i];
        while(current){
            set(current->key, current->value);
            current = current->next;
        }
    }
}

template<typename K, typename V>
void HashMap<K, V>::clear(){
    for(size_t i=0; i<bucketCount; ++i){
        Node* current = buckets[i];
        while(current){
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
        buckets[i] = nullptr;
    }
    elementCount =0;
}

template<typename K, typename V>
size_t HashMap<K, V>::hashFunction(const K& key) const {
    // size_t hash = 0;
    // for(char c: key) {
    //     hash+=c;
    // }
    std::hash<K> hasher;

    return hasher(key)%bucketCount;
}

template<typename K, typename V>
void HashMap<K, V>::rehash(){
    size_t oldBucketCount = bucketCount;
    Node** oldBuckets = buckets;

    bucketCount *= 2;
    elementCount = 0;

    buckets = new Node*[bucketCount];
    for(size_t i=0; i<bucketCount; ++i){
        buckets[i] = nullptr;
    }

    for(size_t i=0; i<oldBucketCount; ++i){
        Node* current = oldBuckets[i];
        while(current){
            set(current->key, current->value);
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }
    delete[] oldBuckets;
}

template<typename K, typename V>
void HashMap<K, V>:: set(const K& key, const V& value){
    size_t index = hashFunction(key);
    Node* current = buckets[index];

    while(current){
        if(current->key == key){
            current->value = value;
            return;
        }
        current = current->next;
    }
    Node* newNode = new Node(key, value);
    newNode->next = buckets[index];
    buckets[index] = newNode;

    elementCount++;

    if(loadFactor() > 0.75f){
        rehash();
    }
}

template<typename K, typename V>
V HashMap<K, V>::get(const K& key) const {
    size_t index = hashFunction(key);
    Node* current = buckets[index];

    while(current){
        if(current->key == key){
            return current->value;
        }
        current = current->next;
    }
    throw std::runtime_error("Key not found");
}

template<typename K, typename V>
bool HashMap<K, V>::exists(const K& key) const {
    size_t index= hashFunction(key);
    Node* current = buckets[index];

    while(current){
        if(current->key == key){
            return true;
        }
        current = current->next;
    }
    return false;
}

template<typename K, typename V>
void HashMap<K, V>::remove(const K& key) {
    size_t index = hashFunction(key);
    Node* current = buckets[index];
    Node* prev = nullptr;

    while(current){
        if(current->key == key){
            if(prev) {
                prev -> next = current->next;
            } else {
                buckets[index] = current->next;
            }

            delete current;
            elementCount--;

            return;
        }
        prev = current;
        current = current->next;
    }
}

template<typename K, typename V>
size_t HashMap<K, V>:: size() const{
    return elementCount;
}

template<typename K, typename V>
bool HashMap<K, V>::empty() const {
    return elementCount == 0;
}

template<typename K, typename V>
float HashMap<K, V>::loadFactor() const {
    return static_cast<float>(elementCount)/bucketCount;
}

template<typename K, typename V>
void HashMap<K, V>::display() const {
    for(size_t i=0; i<bucketCount; ++i){
        std::cout<< "[" << i << "] ";
        Node* curr = buckets[i];
        while(curr){
            std::cout << "(" << curr->key << ":" << curr->value << ") -> ";
            curr = curr->next;
        }
        std::cout << "NULL\n";

    }
}

