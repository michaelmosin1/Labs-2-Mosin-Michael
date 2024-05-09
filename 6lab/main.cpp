#include "my_vector.hpp"


int main(){
    mm::Vector<int> vector(5);
    for (size_t i = 0; i < 5; i++){
        std::cin >> vector[i];
    }
    vector.erase(2);
    vector.push_back(1337);
    vector.insert(228, 3);
    std::cout << vector << std::endl;
    return 0;
}