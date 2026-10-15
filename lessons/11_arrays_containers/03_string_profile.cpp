#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;
using std::getline;

string makeGreeting(const string& name) {
    string greeting = "Hello, " + name + "!";
    return greeting;
}

int countSpaces(const string& text) {
    int sum = 0;
    for (char ch : text) {
        if (ch == ' ') {
            ++sum;
        }
    }

    return sum;
}

void printName(string name) {

    cout << "name.size()" << name.size() << '\n';
    cout << "name[0]" << name[0] << '\n';
    cout << "name[N-1]" << name[name.size() -1] << '\n';

    string greeting = makeGreeting(name);
    cout << "greeting = " << greeting << '\n';
    int sum = countSpaces(name);
    cout << "sum = " << sum << '\n';

    return;
}

int main() {
    string name;
    if (!getline(cin, name)) {
        cout << "Failed" << '\n';
        return 0;
    }
    
    if (name.empty()) {
        cout << "姓名不能为空" << '\n';
    }
    else {
        for (char ch : name) {
            if (!(ch == ' ' || ch == '\n')) {
                printName(name);
                return 0;
            }
        }
        cout << "姓名不能为空" << '\n';
    }

    return 0;
}







