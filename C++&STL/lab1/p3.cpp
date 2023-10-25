/*
Create an alias for a type that is a collection std::unordered_set<> of strings. 
Then declare and initialize such a set using uniform initialization. 
Finally, walk through this set with a range -based for-each loop, 
automatically deducing the type of the set's elements; loop all strings to standard output std::cout).
*/

#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    using StringSet = std::unordered_set<std::string>;
    StringSet mySet = {"apple", "banana", "cherry", "12/22"};
    for (auto str : mySet) {
        std::cout << str << std::endl;
    }
    return 0;
}
