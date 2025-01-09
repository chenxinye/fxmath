#include <floatx.hpp>
#include <fxmath.hpp>

int main ()
{
    using fx16 = flx::floatx<8, 7>; // Define a low-precision float type
    using fxb16 = flx::floatx<5, 10>; // Define a low-precision float type

    fx16 x1 = 0.51212;
    fxb16 x2 = 0.99812462;
    fx16 result = x1 + x2;
    std::cout << fxmath::fx_pow (x1, 2.0f);
    std::cout << fxmath::fx_pow (x2, x1);
    std::cout <<  fxmath::fx_pow (result, x1);
    std::cout << std::endl;
    return 0;
}
