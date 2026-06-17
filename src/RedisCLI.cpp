#include "RedisCLI.hpp"

#include<iostream>
#include<sstream>

using namespace std;

void RedisCLI::run(){
    string line;
    cout << "Redis Lite Started\n";
    cout << "Type 'EXIT' to quit\n";

    while(true){
        cout << "redis> ";
        getline(cin, line);
        if(line.empty()) continue;
        stringstream ss(line);
        string command;
        ss >> command;

        if(command == "EXIT"){
            cout << "Exiting Redis Lite.\n";
            break;
        }
        else if(command == "SET"){
            string key, value;
            ss >> key >> value;
            if(key.empty() || value.empty()){
                cout << "Usage: SET <key> <value>\n";
                continue;
            }
            store.set(key, value);
            cout << "OK\n";
        } else if(command == "GET"){
            string key;
            ss >> key;
            if(key.empty()) {
                cout << "Usage: GET <key>\n";
                continue;
            }
            try {
                string value = store.get(key);
                cout << value << endl;
            } catch(...){
                cout << "Not Found" << endl;
            }
        } else if(command == "DEL"){
            string key;
            ss >> key;
            if(key.empty()){
                cout << "Usage: DEL <key>\n";
                continue;
            }
            if(store.exists(key)){
                store.remove(key);
                cout << "Deleted\n";
            } else {
                cout << "Not Found\n";
            }
        } else if(command == "EXISTS") {
            string key;
            ss >> key;
            if(key.empty()){
                cout << "Usage: EXISTS <key>\n";
                continue;
            }
            cout << (store.exists(key) ? "true" : "false") << endl;
        } else if(command == "COUNT"){
            cout << store.size() << endl;
        } else if(command == "CLEAR"){
            store.clear();
            cout << "Cleared" << endl;
        } else {
            cout << "Unknown Command" << endl;
        }
    }
}