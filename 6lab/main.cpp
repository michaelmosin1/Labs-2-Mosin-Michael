#include "my_vector.hpp"


int main(){
    size_t length = 0;
    std::cout << "Please input length of the vector" << std::endl;
    std::cin >> length;
    std::cout << "Please input number of elements" << std::endl;
    mm::Vector<bool> vector(20);
    for (size_t i = 0; i < 20; i++){
        bool elem;
        std::cin >> elem;
        vector.set_value(i, elem);
    }
    vector.insert(1, 8);
    vector.push_back(1);
    vector.erase(8);
    std::cout << vector[10] << std::endl;
    std::cout << vector << std::endl;
    return 0;
}