#include <iostream>
#include <cstdio>
using std::cout;

class Player {
    private:
        int health_ = 100;

    public:
        Player(int initHealth) : health_(initHealth) {
            if (initHealth <= 0) {
                health_ = 0;
            }
        }

        Player() : health_(100) {}

        void takeDamage(int amount) {
            if (amount <= 0) {
                return;
            }
            if (amount >= health_) {
                health_ = 0;
                return;
            }
            health_ -= amount;
            return;
        }

        int getHealth() const {
            return health_;
        }

        bool isAlive() const {
            return health_ > 0;
        }


};

int main() {
    Player normal{};
    cout << normal.getHealth() << '\n';
    cout << normal.isAlive() << '\n';

    Player custom{80};
    cout << custom.getHealth() << '\n';
    cout << custom.isAlive() << '\n';

    Player empty{0};
    cout << empty.getHealth() << '\n';
    cout << empty.isAlive() << '\n';

    Player invalid{-25};
    cout << invalid.getHealth() << '\n';
    cout << invalid.isAlive() << '\n';

    Player strong{150};
    cout << strong.getHealth() << '\n';
    cout << strong.isAlive() << '\n';

    const Player observer{60};
    cout << observer.getHealth() << '\n';
    cout << observer.isAlive() << '\n';

    custom.takeDamage(30);
    cout << custom.getHealth() << '\n';

    cout << normal.getHealth() << '\n';

    strong.takeDamage(200);
    cout << strong.getHealth() << '\n';

    return 0;
}



