#include <floatx.hpp>
#include <fxmath.hpp>
#include <cmath>
int main ()
{
    using fx16 = flx::floatx<8, 7>; // Define a low-precision float type
    using fxb16 = flx::floatx<5, 10>; // Define a low-precision float type

    fx16 x1 = 0.51212;
    fxb16 x2 = 0;
    std::cout << fxmath::fx_isnormal(x1) << std::endl;
    std::cout << fxmath::fx_isnormal(x2) << std::endl;
    std::cout << std::endl;
    return 0;
}
