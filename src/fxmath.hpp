#ifndef FXMATH_H
#define FXMATH_H

#include <floatx.hpp>
#include <cmath>
#include <iostream>
#include <cassert>

#ifndef FXMATH_BACKEND_FLOAT
    #define BACKEND_FLOAT double
#else
    #define BACKEND_FLOAT float
#endif

#define ERROR_MESSAGE "Please enter a valid floatx type variable, \
         the built-in floating point type follows the usage of math.h."

namespace fxmath{   

template <class FLOAT, class T>
FLOAT fx_rounding(const FLOAT *obj, const T& value) noexcept {
    return flx::floatxr(flx::get_exp_bits(*obj), flx::get_sig_bits(*obj), T(value));
}

// Trigonometric functions

template <class FLOAT> FLOAT fx_sin(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = sin( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_sin(const double &x){
    return sin( x );
}

float fx_sin(const float &x){
    return sin( x );
}

template <class FLOAT> FLOAT fx_cos(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = cos( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_cos(const double &x){
    return cos( x );
}

float fx_cos(const float &x){
    return cos( x );
}

template <class FLOAT> FLOAT fx_tan(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = tan( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_tan(const double &x){
    return tan( x );
}

float fx_tan(const float &x){
    return tan( x );
}

template <class FLOAT> FLOAT fx_acos(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = acos( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_acos(const double &x){
    return acos( x );
}

float fx_acos(const float &x){
    return acos( x );
}

template <class FLOAT> FLOAT fx_atan(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = atan( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_atan(const double &x){
    return atan( x );
}

float fx_atan(const float &x){
    return atan( x );
}

template <class FLOAT1, class FLOAT2> FLOAT1 fx_atan2(const FLOAT1 &x, const FLOAT2 &y){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT1>));
    BACKEND_FLOAT val = atan2( (BACKEND_FLOAT) x, (BACKEND_FLOAT) y );
    return fx_rounding(&x, val);
}

double fx_atan2(const double &x, const double &y){
    return atan2( x, y );
}

float fx_atan2(const float &x, const float &y){
    return atan2( x, y );
}

// Hyperbolic functions

template <class FLOAT> FLOAT fx_cosh(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = cosh( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_cosh(const double &x){
    return cosh( x );
}

float fx_cosh(const float &x){
    return cosh( x );
}

template <class FLOAT> FLOAT fx_sinh(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = sinh( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_sinh(const double &x){
    return sinh( x );
}

float fx_sinh(const float &x){
    return sinh( x );
}

template <class FLOAT> FLOAT fx_tanh(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = tanh( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_tanh(const double &x){
    return tanh( x );
}

float fx_tanh(const float &x){
    return tanh( x );
}

template <class FLOAT> FLOAT fx_acosh(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = acosh( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_acosh(const double &x){
    return acosh( x );
}

float fx_acosh(const float &x){
    return acosh( x );
}

template <class FLOAT> FLOAT fx_asinh(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = asinh( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_asinh(const double &x){
    return asinh( x );
}

float fx_asinh(const float &x){
    return asinh( x );
}

template <class FLOAT> FLOAT fx_atanh(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = atanh( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_atanh(const double &x){
    return atanh( x );
}

float fx_atanh(const float &x){
    return atanh( x );
}

// Exponential and logarithmic functions

template <class FLOAT> FLOAT fx_exp(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = exp( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_exp(const double &x){
    return exp( x );
}

float fx_exp(const float &x){
    return exp( x );
}

template <class FLOAT> FLOAT fx_frexp(const FLOAT &x, const int* exp){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = frexp( (BACKEND_FLOAT) x, exp);
    return fx_rounding(&x, val);
}

double fx_frexp(const double &x, int* exp){
    return frexp( x, exp );
}

float fx_frexp(const float &x, int* exp){
    return frexp( x, exp );
}

template <class FLOAT> FLOAT fx_ldexp(const FLOAT &x, const int exp){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = ldexp( (BACKEND_FLOAT) x, exp);
    return fx_rounding(&x, val);
}

double fx_ldexp(const double &x, const int exp){
    return ldexp( x, exp );
}

float fx_ldexp(const float &x, const int exp){
    return ldexp( x, exp );
}

template <class FLOAT> FLOAT fx_log(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = log( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_log(const double &x){
    return log( x );
}

float fx_log(const float &x){
    return log( x );
}

template <class FLOAT> FLOAT fx_log10(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = log10( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_log10(const double &x){
    return log10( x );
}

float fx_log10(const float &x){
    return log10( x );
}

template <class FLOAT1, class FLOAT2> FLOAT1 fx_modf(const FLOAT1 &x, const FLOAT2* intpart){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT1>));
    BACKEND_FLOAT val = modf( (BACKEND_FLOAT) x, (BACKEND_FLOAT*) intpart);
    return fx_rounding(&x, val);
}

double fx_modf(const double &x, double* intpart){
    return modf( x, intpart );
}

float fx_modf(const float &x, double* intpart){
    return modf( x, intpart );
}

template <class FLOAT> FLOAT fx_exp2(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = exp2( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_exp2(const double &x){
    return exp2( x );
}

float fx_exp2(const float &x){
    return exp2( x );
}

template <class FLOAT> FLOAT fx_expm1(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = expm1( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_expm1(const double &x){
    return expm1( x );
}

float fx_expm1(const float &x){
    return expm1( x );
}

template <class FLOAT> int fx_ilogb(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    return ilogb( (BACKEND_FLOAT) x );
}

int fx_ilogb(const double &x){
    return ilogb( x );
}

int fx_ilogb(const float &x){
    return ilogb( x );
}

template <class FLOAT> FLOAT fx_log1p(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = log1p( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_log1p(const double &x){
    return log1p( x );
}

float fx_log1p(const float &x){
    return log1p( x );
}

template <class FLOAT> FLOAT fx_log2(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = log2( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_log2(const double &x){
    return log2( x );
}

float fx_log2(const float &x){
    return log2( x );
}

template <class FLOAT> FLOAT fx_logb(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = logb( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_logb(const double &x){
    return logb( x );
}

float fx_logb(const float &x){
    return logb( x );
}

template <class FLOAT> FLOAT fx_scalbn(const FLOAT &x, const int n){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = scalbn( (BACKEND_FLOAT) x, n);
    return fx_rounding(&x, val);
}

double fx_scalbn(const double &x, const int n){
    return scalbn( x, n );
}

float fx_scalbn(const float &x, const int n){
    return scalbn( x, n );
}

template <class FLOAT> FLOAT fx_scalbln(const FLOAT &x, const long int n){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = scalbln( (BACKEND_FLOAT) x, n);
    return fx_rounding(&x, val);
}

double fx_scalbln(const double &x, const long int n){
    return scalbln( x, n );
}

float fx_scalbln(const float &x, const long int n){
    return scalbln( x, n );
}

// Power functions

template <class FLOAT, class EXPTYPE> FLOAT fx_pow(const FLOAT &x, const EXPTYPE &exponent){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = pow( (BACKEND_FLOAT) x, (BACKEND_FLOAT) exponent);
    return fx_rounding(&x, val);
}

double fx_pow(const double &x, const double &exponent){
    return pow( x, exponent );
}

float fx_pow(const float &x, const float &exponent){
    return pow( x, exponent );
}

template <class FLOAT> FLOAT fx_cbrt(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = cbrt( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_cbrt(const double &x){
    return cbrt( x );
}

float fx_cbrt(const float &x){
    return cbrt( x );
}

template <class FLOAT1, class FLOAT2> FLOAT1 fx_hypot(const FLOAT1 &x, const FLOAT2 &y){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT1>));
    BACKEND_FLOAT val = hypot( (BACKEND_FLOAT) x, (BACKEND_FLOAT) y);
    return fx_rounding(&x, val);
}

double fx_hypot(const double &x, const double &y){
    return hypot( x, y );
}

float fx_hypot(const float &x, const float &y){
    return hypot( x, y );
}

template <class FLOAT> FLOAT fx_sqrt(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = sqrt( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_sqrt(const double &x){
    return sqrt( x );
}

float fx_sqrt(const float &x){
    return sqrt( x );
}

// Error and gamma functions

template <class FLOAT> FLOAT fx_erf(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = erf( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_erf(const double &x){
    return erf( x );
}

float fx_erf(const float &x){
    return erf( x );
}

template <class FLOAT> FLOAT fx_erfc(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = erfc( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_erfc(const double &x){
    return erfc( x );
}

float fx_erfc(const float &x){
    return erfc( x );
}

template <class FLOAT> FLOAT fx_tgamma(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = tgamma( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_tgamma(const double &x){
    return tgamma( x );
}

float fx_tgamma(const float &x){
    return tgamma( x );
}

template <class FLOAT> FLOAT fx_lgamma(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = lgamma( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_lgamma(const double &x){
    return lgamma( x );
}

float fx_lgamma(const float &x){
    return lgamma( x );
}

// Minimum, maximum, difference functions

template <class FLOAT1, class FLOAT2> FLOAT1 fx_fdim(const FLOAT1 &x, const FLOAT2 &y){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT1>));
    BACKEND_FLOAT val = fdim( (BACKEND_FLOAT) x, (BACKEND_FLOAT) y );
    return fx_rounding(&x, val);
}

double fx_fdim(const double &x, const double &y){
    return fdim( x, y );
}

float fx_fdim(const float &x, const float &y){
    return fdim( x, y );
}

template <class FLOAT1, class FLOAT2> FLOAT1 fx_fmax(const FLOAT1 &x, const FLOAT2 &y){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT1>));
    BACKEND_FLOAT val = fmax( (BACKEND_FLOAT) x, (BACKEND_FLOAT) y);
    return fx_rounding(&x, val);
}

double fx_fmax(const double &x, const double &y){
    return fmax( x, y );
}

float fx_fmax(const float &x, const float &y){
    return fmax( x, y );
}

template <class FLOAT1, class FLOAT2> FLOAT1 fx_fmin(const FLOAT1 &x, const FLOAT2 &y){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT1>));
    BACKEND_FLOAT val = fmin( (BACKEND_FLOAT) x, (BACKEND_FLOAT) y);
    return fx_rounding(&x, val);
}

double fx_fmin(const double &x, const double &y){
    return fmin( x, y );
}

float fx_fmin(const float &x, const float &y){
    return fmin( x, y );
}

// Other functions

template <class FLOAT> FLOAT fx_fabs(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = fabs( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_fabs(const double &x){
    return fabs( x );
}

float fx_fabs(const float &x){
    return fabs( x );
}

template <class FLOAT> FLOAT fx_abs(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = abs( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_abs(const double &x){
    return abs( x );
}

float fx_abs(const float &x){
    return abs( x );
}

template <class FLOAT1, class FLOAT2, class FLOAT3> FLOAT1 fx_fma(const FLOAT1 &x, const FLOAT2 &y, const FLOAT3 &z){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT1>));
    BACKEND_FLOAT val = fma( (BACKEND_FLOAT) x, (BACKEND_FLOAT) y, (BACKEND_FLOAT) z);
    return fx_rounding(&x, val);
}

double fx_fma(const double &x, const double &y, const double &z){
    return fma( x, y, z );
}

float fx_fma(const float &x, const float &y, const float &z){
    return fma( x, y, z );
}

// Floating-point manipulation functions

template <class FLOAT1, class FLOAT2> FLOAT1 fx_nexttoward(const FLOAT1 &x, const FLOAT2 &y){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT1>));
    BACKEND_FLOAT val = nexttoward( (BACKEND_FLOAT) x, (BACKEND_FLOAT) y);
    return fx_rounding(&x, val);
}

double fx_nexttoward(const double &x, const double &y){
    return nexttoward( x, y );
}

float fx_nexttoward(const float &x, const float &y){
    return nexttoward( x, y );
}

template <class FLOAT1, class FLOAT2> FLOAT1 fx_nextafter(const FLOAT1 &x, const FLOAT2 &y){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT1>));
    BACKEND_FLOAT val = nextafter( (BACKEND_FLOAT) x, (BACKEND_FLOAT) y);
    return fx_rounding(&x, val);
}

double fx_nextafter(const double &x, const double &y){
    return nextafter( x, y );
}

float fx_nextafter(const float &x, const float &y){
    return nextafter( x, y );
}

template <class FLOAT1, class FLOAT2> FLOAT1 fx_copysign(const FLOAT1 &x, const FLOAT2 &y){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT1>));
    BACKEND_FLOAT val = copysign( (BACKEND_FLOAT) x, (BACKEND_FLOAT) y);
    return fx_rounding(&x, val);
}

double fx_copysign(const double &x, const double &y){
    return copysign( x, y );
}

float fx_copysign(const float &x, const float &y){
    return copysign( x, y );
}

// Remainder 

template <class FLOAT1, class FLOAT2> FLOAT1 fx_remainder(const FLOAT1 &x, const FLOAT2 &y){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT1>));
    BACKEND_FLOAT val = remainder( (BACKEND_FLOAT) x, (BACKEND_FLOAT) y);
    return fx_rounding(&x, val);
}

double fx_remainder(const double &x, const double &y){
    return remainder( x, y );
}

float fx_remainder(const float &x, const float &y){
    return remainder( x, y );
}

template <class FLOAT1, class FLOAT2> FLOAT1 fx_remquo(const FLOAT1 &x, const FLOAT2 &y, const int* quot){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT1>));
    BACKEND_FLOAT val = remquo( (BACKEND_FLOAT) x, (BACKEND_FLOAT) y, quot);
    return fx_rounding(&x, val);
}

double fx_remquo(const double &x, const double &y, int* quot){
    return remquo( x, y, quot );
}

float fx_remquo(const float &x, const float &y, int* quot){
    return remquo( x, y, quot );
}

template <class FLOAT> FLOAT fx_nearbyint(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    BACKEND_FLOAT val = nearbyint( (BACKEND_FLOAT) x );
    return fx_rounding(&x, val);
}

double fx_nearbyint(const double &x){
    return nearbyint( x );
}

float fx_nearbyint(const float &x){
    return nearbyint( x );
}

// misc

template <class FLOAT> bool fx_isnormal(const FLOAT &x){
    assert((ERROR_MESSAGE, !std::is_floating_point_v<FLOAT>));
    bool val = std::isnormal( (BACKEND_FLOAT) x );
    return val;
}

bool fx_isnormal(const double &x){
    return std::isnormal( x );
}

bool fx_isnormal(const float &x){
    return std::isnormal( x );
}

} // end namespace

#endif // FXMATH_H
