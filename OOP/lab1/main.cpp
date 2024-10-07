#include <iostream>
#include "flatmap.h"

int main() {
    FlatMap map;
    map.insert("John", {25, 70});
    map.insert("Jane", {30, 60});

    std::cout << "Size: " << map.size() << std::endl;
    std::cout << "John's age: " << map.at("John").age << std::endl;
    std::cout << "Jane's weight: " << map.at("Jane").weight << std::endl;

    return 0;
}