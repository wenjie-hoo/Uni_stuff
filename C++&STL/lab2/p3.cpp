/*
定义一个类llama代表一群美洲驼中的单个美洲驼（在构造函数和析构函数中编写有关美洲驼的个性化消息）。
这个对象应该包含美洲驼类型的名称string （名称在群体中应该是唯一的）其性别作为枚举类型
指向该类型的父亲和母亲的指针shared_ptr<llama> （我们允许未知父亲或母亲的情况标记为 noname)
以及指向其类型children 的集合的指针 vector<weak_ptr<llama>>。
让骆驼群成为这种类型的对象的集合llama - 例如
您可以包装一些流行的标准集合 set<llama>（按名称比较骆驼）。模拟羊驼在羊群中的生活：饲养员可以从另一个羊群购买一只羊驼（那么它的父母未知）
羊驼可以在羊群中出生（那么它的父母是羊群的成员或者在至少是母亲）
最后骆驼可以被出售（然后必须将其从收藏中删除）。观察当弱指针weak_ptr 变成挂指针时（父指针释放资源后shared_ptr）会发生什么。
*/

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <set>
using namespace std;
enum class LlamaGender { Male, Female };

class llama {
public:
    llama(const std::string& name, LlamaGender gender, std::shared_ptr<llama> father, std::shared_ptr<llama> mother)
        : name(name), gender(gender), father(father), mother(mother) {
        std::cout << "Llama named " << name << " has been born." << std::endl;}

    ~llama() {
        std::cout << "Llama named " << name << " has left the herd." << std::endl;
    }

    std::string getName() const {
        return name;
    }

    LlamaGender getGender() const {
        return gender;
    }

private:
    std::string name;
    LlamaGender gender;
    std::shared_ptr<llama> father;
    std::shared_ptr<llama> mother;
};

int main() {
    std::set<std::shared_ptr<llama>> llamaHerd;
    std::shared_ptr<llama> llama1 = std::make_shared<llama>("Llama1", LlamaGender::Female, nullptr, nullptr);
    std::shared_ptr<llama> llama2 = std::make_shared<llama>("Llama2", LlamaGender::Male, nullptr, nullptr);
    // std::shared_ptr<llama> llama4 = std::make_shared<llama>("Llama4", LlamaGender::Female, nullptr, nullptr);
    llamaHerd.insert(llama1);
    llamaHerd.insert(llama2);

    std::shared_ptr<llama> llama3 = std::make_shared<llama>("Llama3", LlamaGender::Female, llama1, llama2);
    llamaHerd.insert(llama3);
    // std::shared_ptr<llama> llama4 = std::make_shared<llama>("Llama4", LlamaGender::Female, llama1, llama3);
    // llamaHerd.insert(llama4); 

    // llamaHerd.erase(llama2);
    // llamaHerd.erase(llama1);
    llamaHerd.erase(llama3);
    std::vector<std::weak_ptr<llama>> childrenOfLlama3;
    childrenOfLlama3.push_back(llama3);
    // llamaHerd.insert(llama1); 
    
    for (const auto& weakChild : childrenOfLlama3) {
        if (auto sharedChild = weakChild.lock()) {
            std::cout << "Child's name: " << sharedChild->getName() << std::endl;
        } else {
            std::cout << "Child's parent is no longer in the herd." << std::endl;
        }
    }
    return 0;
}
