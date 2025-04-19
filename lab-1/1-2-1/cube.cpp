#include <iostream>

int cube (const int* pd){
    int result;
    result = (*pd) * (*pd) * (*pd);
    return result;
}

int main(){
    int input;
    std::cin >> input;

    input = cube(&input);

    std::cout << input << std::endl;
    return 0;
}
