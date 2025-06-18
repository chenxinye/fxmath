#include <half_promise.hpp>
#include <floatx.hpp>
#include <chrono>
#include <vector>
#include <iostream>
#include <random>

const int N = 100;

template <typename T>
void initialize_matrix(std::vector<std::vector<T>>& matrix) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0.0f, 1.0f);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = T(dis(gen));
        }
    }
}

template <typename T>
void matrix_multiply(const std::vector<std::vector<T>>& A,
                     const std::vector<std::vector<T>>& B,
                     std::vector<std::vector<T>>& C) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            T sum(0);
            for (int k = 0; k < N; ++k) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

// Hadamard product (element-wise multiplication)
template <typename T>
void hadamard_product(const std::vector<std::vector<T>>& A,
                      const std::vector<std::vector<T>>& B,
                      std::vector<std::vector<T>>& C) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = A[i][j] * B[i][j];
        }
    }
}

template <typename T>
void matrix_subtract(const std::vector<std::vector<T>>& A,
                     const std::vector<std::vector<T>>& B,
                     std::vector<std::vector<T>>& C) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

template <typename T>
T matrix_sum(const std::vector<std::vector<T>>& A) {
    T sum(0);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            sum += A[i][j];
        }
    }
    return sum;
}

template <typename T, typename Func>
double measure_time(Func operation, const std::string& op_name) {
    auto start = std::chrono::high_resolution_clock::now();
    operation();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << op_name << " (" << typeid(T).name() << "): "
              << duration.count() / 1000.0 << " ms\n";
    return duration.count() / 1000.0;
}

int main() {
    using half = half_float::half;
    using floatx = flx::floatx<5, 10>;

    std::vector<std::vector<half>> A_half(N, std::vector<half>(N));
    std::vector<std::vector<half>> B_half(N, std::vector<half>(N));
    std::vector<std::vector<half>> C_half(N, std::vector<half>(N));
    std::vector<std::vector<floatx>> A_floatx(N, std::vector<floatx>(N));
    std::vector<std::vector<floatx>> B_floatx(N, std::vector<floatx>(N));
    std::vector<std::vector<floatx>> C_floatx(N, std::vector<floatx>(N));

    initialize_matrix(A_half);
    initialize_matrix(B_half);
    initialize_matrix(A_floatx);
    initialize_matrix(B_floatx);

    std::cout << "\nMatrix Multiplication:\n";
    double time_half_mult = measure_time<half>(
        [&]() { matrix_multiply(A_half, B_half, C_half); },
        "Matrix Multiply"
    );
    double time_floatx_mult = measure_time<floatx>(
        [&]() { matrix_multiply(A_floatx, B_floatx, C_floatx); },
        "Matrix Multiply"
    );

    std::cout << "\nHadamard Product:\n";
    double time_half_hadamard = measure_time<half>(
        [&]() { hadamard_product(A_half, B_half, C_half); },
        "Hadamard Product"
    );
    double time_floatx_hadamard = measure_time<floatx>(
        [&]() { hadamard_product(A_floatx, B_floatx, C_floatx); },
        "Hadamard Product"
    );

    std::cout << "\nMatrix Subtraction:\n";
    double time_half_sub = measure_time<half>(
        [&]() { matrix_subtract(A_half, B_half, C_half); },
        "Matrix Subtract"
    );
    double time_floatx_sub = measure_time<floatx>(
        [&]() { matrix_subtract(A_floatx, B_floatx, C_floatx); },
        "Matrix Subtract"
    );

    std::cout << "\nMatrix Summation:\n";
    double time_half_sum = measure_time<half>(
        [&]() { matrix_sum(A_half); },
        "Matrix Sum"
    );
    double time_floatx_sum = measure_time<floatx>(
        [&]() { matrix_sum(A_floatx); },
        "Matrix Sum"
    );

    std::cout << "\nSummary (Time in ms):\n";
    std::cout << "Operation         | half_float::half | flx::floatx<5,10>\n";
    std::cout << "------------------|------------------|------------------\n";
    std::cout << "Matrix Multiply   | " << time_half_mult << " | " << time_floatx_mult << "\n";
    std::cout << "Hadamard Product  | " << time_half_hadamard << " | " << time_floatx_hadamard << "\n";
    std::cout << "Matrix Subtract   | " << time_half_sub << " | " << time_floatx_sub << "\n";
    std::cout << "Matrix Sum        | " << time_half_sum << " | " << time_floatx_sum << "\n";

    return 0;
}
