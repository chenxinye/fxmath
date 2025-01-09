# fxmath

**fxmath** is a header-only C++ library for performing mathematical operations in simulated low-precision environments using [FloatX](https://github.com/oprecomp/FloatX). It replicates nearly all functionality of the C/C++ standard library's `math.h` or `<cmath>` headers, allowing users to conduct low-precision numerical experiments seamlessly. This makes it ideal for research and applications in numerical analysis, machine learning, and energy-efficient computing.

## Features

- Full support for mathematical operations simulated in low precisions as defined by FloatX.
- Covers most functions from the C/C++ standard library's `math.h`/`<cmath>`.
- Designed for easy integration with existing projects requiring custom precision simulations.
- Lightweight and easy to use.


## Functions

fxmath implements most of the functions in `math.h`/`<cmath>`:

- **Basic Arithmetic**: `fabs`, `fmod`, `remainder`, `ceil`, `floor`, `round`
- **Exponential and Logarithmic**: `exp`, `log`, `log10`, `log2`, `pow`
- **Trigonometric**: `sin`, `cos`, `tan`, `asin`, `acos`, `atan`, `atan2`
- **Hyperbolic**: `sinh`, `cosh`, `tanh`, `asinh`, `acosh`, `atanh`
- **Special Functions**: `sqrt`, `cbrt`, `hypot`
- **Error and Gamma Functions**: `erf`, `erfc`, `tgamma`, `lgamma`

One can use these functions simply by adding the prefix "fx_" to the function names.
All function instructions follows [math functions](https://en.cppreference.com/w/cpp/header/cmath) except the float numbers are replaced with floatx numbers. 


## Getting Started

### Prerequisites

- **FloatX**: fxmath relies on the FloatX library to define and handle custom low-precision floating-point types. You can find and install FloatX from its [GitHub repository](https://github.com/oprecomp/FloatX).

### Installation

Clone the repository:
```bash
git clone https://github.com/chenxinye/fxmath.git
cd fxmath
```

Build and integrate fxmath into your project:
```bash
make
```

Or include it directly in your codebase by adding the relevant files.

## Usage

1. **Include fxmath in your project**:
   ```cpp
   #include "fxmath.hpp"
   ```

2. **Set up FloatX types**:
   Define custom low-precision floating-point types using FloatX.
   ```cpp
   #include <floatx.hpp>

   using fx8 = flx::floatx<8, 23>; // Define a FloatX type (8-bit exponent, 23-bit mantissa)
   ```

3. **Perform mathematical operations**:
   Use fxmath functions with FloatX-defined types.
   ```cpp
   #include <floatx.hpp>

   fx8 a = 3.14;
   fx8 b = fxmath::fx_sin(a);
   ```

More examples can be viewed at inside the folder ''examples''.

## Contributions

Contributions are welcome! If you would like to contribute to the project (encounter bugs, submit feature requests), feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- The [FloatX](https://github.com/oprecomp/FloatX) library for enabling customizable low-precision floating-point arithmetic.
- The broader numerical computing and open-source community for inspiration and tools.
