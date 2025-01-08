#include <floatx.hpp>
#include <fxmath.hpp>

int main() {
    using fx16 = flx::floatx<8, 7>; // Define a low-precision float type

    fx16 x = 0.5;
    fx16 result = fxmath::fx_exp(x); // Compute e^x in simulated low precision

    std::cout << "exp(" << x << ") = " << result << std::endl;
    return 0;
}