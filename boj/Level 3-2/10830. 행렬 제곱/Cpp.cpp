#include <iostream>
#include <vector>

class SquareMatrix
{
private:
    const int mod = 1000;
    std::vector<std::vector<int>> mat;
public:
    SquareMatrix() = delete;
    explicit SquareMatrix(int n) {
        mat.resize(n);
        for (int i = 0; i < n; ++i) {
            mat[i].resize(n);
        }
    }
    SquareMatrix(const SquareMatrix& rhs) {
        mat = rhs.mat;
    }
    SquareMatrix(SquareMatrix&& rhs) noexcept{
        mat = std::move(rhs.mat);
    }
    SquareMatrix& operator=(const SquareMatrix& rhs){
        mat = rhs.mat;
        return *this;
    }
    SquareMatrix& operator=(SquareMatrix && rhs) noexcept{
        mat = std::move(rhs.mat);
        return *this;
    }
    std::vector<int>& operator[](int i) {
        return mat[i];
    }
    const std::vector<int>& operator[](int i) const {
        return mat[i];
    }
    SquareMatrix operator^(long long exponent) {
        const int matSize = static_cast<int>(mat.size());

        SquareMatrix result(matSize);
        for (int i = 0; i < matSize; ++i) {
            for (int j = 0; j < matSize; ++j) {
                result.mat[i][j] = (i == j) ? 1 : 0;
            }
        }

        SquareMatrix base = *this;
        for (; exponent > 0; exponent /= 2) {
            if (exponent % 2 != 0) {
                result = base * result;
            }
            base *= base;
        }

        return result;
    }
    SquareMatrix& operator^=(long long exponent) {
        *this = this->operator^(exponent);
        return *this;
    }
    SquareMatrix operator*(SquareMatrix& rhs) {
        const int matSize = static_cast<int>(mat.size());
        SquareMatrix result(matSize);

        auto& newMat = result.mat;
        for (int i = 0; i < matSize; ++i) {
            for (int j = 0; j < matSize; ++j) {
                for (int k = 0; k < matSize; ++k) {
                    newMat[i][j] += mat[i][k] * rhs.mat[k][j];
                }

                newMat[i][j] %= mod;
            }
        }

        return result;
    }
    SquareMatrix& operator*=(SquareMatrix& rhs) {
        *this = this->operator*(rhs);
        return *this;
    }
};

int main() {
    int N;
    long long B;
    std::cin >> N >> B;

    SquareMatrix A(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> A[i][j];
        }
    }

    A ^= B;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << A[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}