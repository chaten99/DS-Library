#ifndef REDISCLI_H
#define REDISCLI_H

#include<string>
#include "HashMap.hpp"

class RedisCLI {
    private:
        HashMap<std::string, std::string> store;
    public:
        void run();
};

#include "../src/RedisCLI.cpp"

#endif