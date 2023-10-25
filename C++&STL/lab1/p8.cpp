#include <iostream>
#include <deque>

struct osoba {
    std::string surname;
    std::string name;
    std::string gender;

    bool operator<(const osoba& other) const {
        return std::tie(surname, name, gender) < std::tie(other.surname, other.name, other.gender);
    }
};

int main() {
    std::deque<osoba> people = {
        {"S", "John", "M"},
        {"D", "Alice", "F"},
        {"J", "Bob", "M"},
        {"A", "Emily", "F"}
    };

    std::sort(people.begin(), people.end());

    for (const osoba& person : people) {
        std::cout << "Surname: " << person.surname << ", Name: " << person.name << ", Gender: " << person.gender << std::endl;
    }

    return 0;
}



