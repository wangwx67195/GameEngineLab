#include <iostream>
#include <cstdio>
using std::cout;

class LifetimeProbe {
    private:
        int id_;
    public:
        LifetimeProbe(int initValue) : id_(initValue) {
            cout << "construct " << id_ << '\n';
        }
        ~LifetimeProbe() {
            cout << "destory " << id_ << '\n';
        }

        void ping() const {
            cout << "ping " << id_ << '\n';
        }
};

void visitScope() {
    LifetimeProbe id4(4);
    return;
}

int main() {
    LifetimeProbe id1(1);

    cout << "before block" << '\n';
    {
        LifetimeProbe id2(2);
        LifetimeProbe id3(3);

        cout << "inside block" << '\n';
    }

    cout << "after block" << '\n';
    id1.ping();

    visitScope();
    cout << "after visit" << '\n';

    cout << "main end" << '\n';
    return 0;
}


