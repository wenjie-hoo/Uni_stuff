#include <iostream>
#include <deque>
#include <algorithm>
#include <random>
using namespace std;

class Person{
public:
    string name;
    string surname;
    int age;
    double weight;
    double height;

    Person(std::string n, std::string s, int a, double w, double h) : name(std::move(n)), surname(std::move(s)), age(a), weight(w), height(h) {}

    double getBMI() const{
        return weight / (height * height);}

    void loseWeight(){
        weight *= 0.9;}
};

void sortByBMI(deque<Person> &persons){
    sort(persons.begin(), persons.end(),
    [](const Person &a, const Person &b){return a.getBMI() < b.getBMI();});
}

void slimDown(deque<Person> &persons){
    for_each(persons.begin(), persons.end(),[](Person &person){person.loseWeight();});
}

void divideByWeight(deque<Person> &persons,
                    deque<Person> &heavy,
                    deque<Person> &light)
{
    auto partitionIt = partition(persons.begin(), persons.end(),
                                 [](const Person &person)
                                 {
                                     return person.weight > 100.0;
                                 });

    heavy.assign(persons.begin(), partitionIt);
    light.assign(partitionIt, persons.end());
}

void middleHeightPerson(deque<Person> &persons){
    size_t middleIndex = persons.size() / 2;
    iter_swap(persons.begin() + 4, persons.begin() + middleIndex);
}

void randomRearrange(deque<Person> &persons){
    random_device rd;
    mt19937 g(rd());
    shuffle(persons.begin(), persons.begin() + 5, g);
    shuffle(persons.end() - 5, persons.end(), g);
}

void oldestAndYoungest(const deque<Person> &persons){
    auto minMax = minmax_element(persons.begin(), persons.end(),
                                 [](const Person &a, const Person &b)
                                 {
                                     return a.age < b.age;
                                 });

    cout << "Oldest person: " << minMax.second->name << " " << minMax.second->surname
         << " Age: " << minMax.second->age << "\n";
    cout << "Youngest person: " << minMax.first->name << " " << minMax.first->surname
         << " Age: " << minMax.first->age << "\n";
}

int main(){
    deque<Person> persons = {
        {"John", "Doe", 25, 80.0, 1.75},
        {"Jane", "Smith", 34, 74.0, 1.65},
        {"Jack", "Ma", 32, 63.0, 1.72},
        {"Alex", "Webb", 18, 62.0, 1.95},
        {"Luca", "Russo", 24, 85.0, 1.83},
        {"Alice", "Johnson", 42, 91.0, 1.81}};

    cout << "Sorted by BMI:\n";
    sortByBMI(persons);
    for_each(persons.begin(), persons.end(), [](const Person &person)
             { cout << person.name << " " << person.surname << " BMI: " << person.getBMI() << "\n"; });

    cout << "\nAfter slimming down:\n";
    slimDown(persons);
    for_each(persons.begin(), persons.end(), [](const Person &person)
             { cout << person.name << " " << person.surname << " Weight: " << person.getBMI() << "\n"; });

    deque<Person> heavy, light;
    divideByWeight(persons, heavy, light);

    cout << "\nHeavy people:\n";
    for_each(light.begin(), light.end(), [](const Person &person)
             { cout << person.name << " " << person.surname << " Weight: " << person.weight << "\n"; });

    cout << "\nLight people:\n";
    for_each(light.begin(), light.end(), [](const Person &person)
             { cout << person.name << " " << person.surname << " Weight: " << person.weight << "\n"; });

    middleHeightPerson(persons);

    cout << "\nMiddle height person set to position 5:\n";
    for_each(light.begin(), light.end(), [](const Person &person)
             { cout << person.name << " " << person.surname << " Height: " << person.weight << "\n"; });

    randomRearrange(persons);
    cout << "\nRandomly rearranged:\n";
    for_each(light.begin(), light.end(), [](const Person &person)
             { cout << person.name << " " << person.surname << " " << person.weight << "\n"; });

    oldestAndYoungest(persons);
    return 0;
}
