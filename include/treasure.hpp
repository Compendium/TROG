#ifndef TREASURE_H
#define TREASURE_H

#include <string>
#include "item.hpp"

class Treasure : public Item {
    public:
    Treasure(int n);
    ~Treasure(void);
    std::string GetName(void);

    int quantity;
    std::string name;
};

#endif
