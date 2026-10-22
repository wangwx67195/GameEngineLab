#include <iostream>
#include <cstdio>
#include <memory>
using std::cout;
using std::unique_ptr;
using std::make_unique;

class LifetimeProbe {
    private:
        int id_;

    public:
        LifetimeProbe(int initValue) : id_(initValue) {
            cout << "construct " << id_ << '\n';
        }
        ~LifetimeProbe() {
            cout << "destroy " << id_ << '\n';
        }

        void ping() {
            cout << "ping " << id_ << '\n';
        }

};

void visitOwnedScope(bool leaveEarly) {
    unique_ptr<LifetimeProbe> p3 = make_unique<LifetimeProbe>(303);
    if (leaveEarly) {
        cout << "early return" << '\n';
        return;
    }
    else {
        p3 -> ping();
        cout << "normal end" << '\n';
    }

    cout << "END of the whole FUNC" << '\n';

    return;
}

int main() {
    {
        unique_ptr<LifetimeProbe> p1 = make_unique<LifetimeProbe>(101);
        p1 -> ping();

        cout << "leave block" << '\n';
    }

    cout << "after block" << '\n';

    {
        unique_ptr<LifetimeProbe> p2 = make_unique<LifetimeProbe>(202);
        cout << "before reset" << '\n';
        p2.reset();
        cout << "after reset" << '\n';
        cout << "p2 == nullptr " << (p2 == nullptr) << '\n';
    }

    cout << "after block" << '\n';

    cout << "before void true" << '\n';
    visitOwnedScope(true);
    cout << "after void true" << '\n';

    cout << "before void false" << '\n';
    visitOwnedScope(false);
    cout << "after void false" << '\n';

    return 0;
}



