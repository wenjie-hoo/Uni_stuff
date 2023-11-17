//  Reverse Polish Notation 
#include <iostream>
#include <stack>
#include <set>
#include <queue>
using namespace std;

bool in (char e, set <char> s) {
    if (s.find(e) != s.end())
        return true;
    return false;    
}

void print(queue <char> q) {
    while( !q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}

bool isOperator(char c) {
    char operators[] = {'+', '-', '/', '*', '^', '%'};
    set<char> operatorSet(operators, operators + 6);
    return operatorSet.find(c) != operatorSet.end();
}

bool isPriorityOperator(char c) {
    char priorityOperators[] = {'/', '*', '^', '%'};
    set<char> prioritySet(priorityOperators, priorityOperators + 4);
    return prioritySet.find(c) != prioritySet.end();
}

bool isBracket(char c) {
    char brackets[] = {'(', ')'};
    set<char> bracketSet(brackets, brackets + 2);
    return bracketSet.find(c) != bracketSet.end();
}

queue<char> shuntingYard(string infix) {
    stack<char> operators;
    queue<char> postfix;

    for (int i = 0; i < infix.length(); i++) {
        char currentChar = infix[i];
        if (isOperator(currentChar)) {
            while (!operators.empty()) {
                char topOperator = operators.top();
                if (isOperator(topOperator) && currentChar != '^' &&
                    (!isPriorityOperator(currentChar) || isPriorityOperator(topOperator))) {
                    postfix.push(topOperator);
                    operators.pop();
                } else {
                    break;
                }
            }
            operators.push(currentChar);
        } else {
            if (isBracket(currentChar)) {
                if (currentChar == '(') {
                    operators.push(currentChar);
                } else {
                    while (!operators.empty()) {
                        char topOperator = operators.top();
                        if (topOperator != '(') {
                            postfix.push(topOperator);
                            operators.pop();
                        } else {
                            operators.pop(); // Pop '('
                            break;
                        }
                    }
                }
            } else {
                postfix.push(currentChar);
            }
        }
    }

    while (!operators.empty()) {
        postfix.push(operators.top());
        operators.pop();
    }
    return postfix;
}


int main() {
    queue <char> t1 = shuntingYard("(1+2)*(3+4)");
    queue <char> t2 = shuntingYard("3+4*2/(3-2)^2");
    queue <char> t3 = shuntingYard("1+4/3/3^2");
    queue <char> t4 = shuntingYard("(2*4/2^3%2*3)");
    cout << "---- (1+2)×(3+4) ---- \n";
    print(t1);
    cout << "---- 3+4*2/(3-2)^2 ---- \n";
    print(t2);
    cout << "---- 1+4/3/3^2 ---- \n";
    print(t3);
    cout << "---- 2*4/2^3%2*3 ---- \n";
    print(t4);
    return 0;
}