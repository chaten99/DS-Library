#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <string>
#include <stdexcept>
#include<functional>

template<typename K, typename V>
class HashMap {
    private:
        struct Node {
            K key;
            V value;
            Node* next;
            Node(const K& k, const V& v) : key(k), value(v), next(nullptr) {}
        };

        Node** buckets;

        size_t bucketCount;
        size_t elementCount;

        size_t hashFunction(const K& key) const;
        void rehash();
        void copyFrom(const HashMap& other);

        public:
        HashMap();
        ~HashMap();

        HashMap(const HashMap& other);
        HashMap& operator=(const HashMap& other);

        void set(const K& key, const V& value);
        V get(const K& key) const;
        bool exists(const K& key) const;
        void remove(const K& key);

        size_t size() const;
        bool empty() const;
        float loadFactor() const;
        void clear();

        void display() const;
};

#include "../src/HashMap.cpp"

#endif