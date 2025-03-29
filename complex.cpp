#include <iostream>
#include "complex_number.hpp"

int main() 
{
    using comp = complex_number<double>;
    
    comp c1(1.0, 2.0);
    comp c2(3.0, -1.0);
    
    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;
    
    comp sum = c1 + c2;
    std::cout << "c1 + c2 = " << sum << std::endl;
    
    comp product = c1 * c2;
    std::cout << "c1 * c2 = " << product << std::endl;
    
    comp conj_c1 = c1.conjugate();
    std::cout << "Conjugate of c1 = " << conj_c1 << std::endl;
	
	comp conj_c2 = c2.conjugate();
    std::cout << "Conjugate of c2 = " << conj_c2 << std::endl;
    
    comp scalar_sum = c1 + 5.0;
    std::cout << "c1 + 5 = " << scalar_sum << std::endl;
    
    comp scalar_product = 2.0 * c2;
    std::cout << "2 * c2 = " << scalar_product << std::endl;
    
    return 0;
}
