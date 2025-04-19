#include <iostream>

void rotateLeft(int* pa, int* pb, int* pc) {
    int temp = *pa;
    *pa = *pb;
    *pb = *pc;
    *pc = temp;
}
void rotateRight(int* pa, int* pb, int* pc) {
    int temp = *pc;
    *pc = *pb;
    *pb = *pa;
    *pa = temp;
}

int main(){
    int a = 10;
    int b = 20;
    int c = 30;

    char input = 'x';
    while (input != 'E'){
        std::cout << a << ":" << b << ":" << c << std::endl;
        std::cin >> input;

        if (input == 'L'){
            rotateLeft(&a, &b, &c);
        }
        else if (input == 'R'){
            rotateRight(&a, &b, &c);
        }
        else if (input != 'E'){
            std::cout << "Error: Wrong input!" << std::endl;
            continue;
        }
    }
}
