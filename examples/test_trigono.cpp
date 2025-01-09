#include <floatx.hpp>
#include <fxmath.hpp>
// #define FXMATH_BACKEND_FLOAT

int main() {
    
    
    using fx16 = flx::floatx<8, 7>; // Define a low-precision float type
    using fxb16 = flx::floatx<5, 10>; // Define a low-precision float type

    fx16 x1 = 0.51212;
    fxb16 x2 = 0.99812462;
    fx16 result;
    result = fxmath::fx_sin(x1); // Compute e^x in simulated low precision

    std::cout << "sin(" << x1 << ") = " << result << std::endl;

    result = fxmath::fx_sin(x2); // Compute e^x in simulated low precision

    std::cout << "sin(" << x2 << ") = " << result << std::endl;

    result = fxmath::fx_atan(x1); // Compute e^x in simulated low precision

    std::cout << "atan(" << x1 << ") = " << result << std::endl;

    result = fxmath::fx_atan2(x1, x2); // Compute e^x in simulated low precision

    std::cout << "atan2(" << "("<< x1 << ", "<< x2<< ") = " << result << std::endl;
    return 0;
}
