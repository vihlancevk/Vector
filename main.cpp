#include "Vector.hpp"

int main() {
    Vector<double, 5> vec1;
    vec1[1] = 2.0;
    vec1.print_vector();

    std::cout << "\n";

    const Vector<int, 1> vec2;
    // vec2[0] = 5;
    vec2.print_vector();

    std::cout << "\n";

    Vector<double, 5> vec3(vec1);
    vec3.print_vector();
    std::cout << &(vec1[0]) << " " << &(vec3[0]) << "\n";

    std::cout << "\n";

    Vector<double, 5> vec4;
    vec4[0] = 5.0;
    vec4[4] = 8.0;
    vec4.print_vector();

    std::cout << "\n";

    vec1 = vec4;
    vec1.print_vector();

    return 0;
}