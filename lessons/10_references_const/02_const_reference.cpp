#include <iostream>
#include <cstdio>

void printValue(const int& value) {
    printf("value = %d \n", value);
    // value += 10;

    return;
}

int main() {
    int a = 10;
    const int b = 10;

    printValue(a);
    printValue(b);




    return 0;
}




