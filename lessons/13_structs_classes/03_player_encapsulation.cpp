#include <iostream>
#include <cstdio>
using std::cout;

class Player {
    private:
        int health_ = 100;
    
    public:

        void takeDamage(int amount) {
            if (amount <= 0) {
                return;
            }

            if (health_ == 0) {
                return;
            }

            health_ -= amount;
            if (health_ <= 0) {
                health_ = 0;
            }

            return;
        }

        int getHealth() const {
            return health_;
        }

        bool isAlive() const {
            if (health_ > 0) {
                return true;
            }
            else {
                return false;
            }
        }


};

int main() {
    Player hero{};
    Player other{};

    int heroHealth = hero.getHealth();
    bool heroAlive = hero.isAlive();
    cout << "heroHealth = " << heroHealth << '\n';
    cout << "hero_Alive = " << heroAlive << '\n';

    hero.takeDamage(30);
    heroHealth = hero.getHealth();
    heroAlive = hero.isAlive();
    cout << "heroHealth = " << heroHealth << '\n';
    cout << "hero_Alive = " << heroAlive << '\n';

    hero.takeDamage(0);
    heroHealth = hero.getHealth();
    heroAlive = hero.isAlive();
    cout << "heroHealth = " << heroHealth << '\n';
    cout << "hero_Alive = " << heroAlive << '\n';

    hero.takeDamage(-10);
    heroHealth = hero.getHealth();
    heroAlive = hero.isAlive();
    cout << "heroHealth = " << heroHealth << '\n';
    cout << "hero_Alive = " << heroAlive << '\n';

    hero.takeDamage(1000);
    heroHealth = hero.getHealth();
    heroAlive = hero.isAlive();
    cout << "heroHealth = " << heroHealth << '\n';
    cout << "hero_Alive = " << heroAlive << '\n';

    hero.takeDamage(10);
    heroHealth = hero.getHealth();
    heroAlive = hero.isAlive();
    cout << "heroHealth = " << heroHealth << '\n';
    cout << "hero_Alive = " << heroAlive << '\n';

    int otherHealth = other.getHealth();
    bool otherAlive = other.isAlive();
    cout << "otherHealth = " << otherHealth << '\n';
    cout << "other_Alive = " << otherAlive << '\n';

    const Player observer{};
    int observerHealth = observer.getHealth();
    bool observerAlive = observer.isAlive();
    cout << "observerHealth = " << observerHealth << '\n';
    cout << "observer_Alive = " << observerAlive << '\n';

    Player newplayer{};
    int newplayerHealth = newplayer.getHealth();
    bool newplayerAlive = newplayer.isAlive();
    cout << "newplayerHealth = " << newplayerHealth << '\n';
    cout << "newplayer_Alive = " << newplayerAlive << '\n';  
    newplayer.takeDamage(100);
    newplayerHealth = newplayer.getHealth();
    newplayerAlive = newplayer.isAlive();
    cout << "newplayerHealth = " << newplayerHealth << '\n';
    cout << "newplayer_Alive = " << newplayerAlive << '\n';

    // hero.health_ = -20;

    return 0;
}



