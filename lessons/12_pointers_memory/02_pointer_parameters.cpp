#include <iostream>
#include <cstdio>
using std::cout;

bool applyDamage(int* health, int damage) {
    if (health == nullptr || damage < 0) {
        return false;
    }
    
    *health -= damage;
    if (*health <= 0) {
        *health = 0;
    }

    return true;
}

int main() {
    int health = 80;
    int damage = 15;
    int* p = &health;

    bool health1 = applyDamage(p, damage);
    cout << "health1 = " << health1 << '\n';
    cout << "health = " << health << '\n';

    damage = 100;
    bool health2 = applyDamage(p, damage);
    cout << "health2 = " << health2 << '\n';
    cout << "health = " << health << '\n';

    p = nullptr;
    damage = 10;
    bool health3 = applyDamage(p, damage);
    cout << "health3 = " << health3 << '\n';
    cout << "health = " << health << '\n';

    health = 50;
    p = &health;
    damage = 0;
    bool health4 = applyDamage(p, damage);
    cout << "health4 = " << health4 << '\n';
    cout << "health = " << health << '\n';

    damage = -5;
    bool health5 = applyDamage(p, damage);
    cout << "health5 = " << health5 << '\n';
    cout << "health = " << health << '\n';


    return 0;
}




