#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Sparse>

template <typename Derived>
void myfunc(Eigen::MatrixBase<Derived> &b, double multiplier)
{
    b *= multiplier;
}

template <typename Derived, typename SparseDerived>
void myfunc_complex(
    Eigen::MatrixBase<Derived> &D, 
    Eigen::SparseMatrixBase<SparseDerived> &Dsp, 
    double multiplier)
{
    D *= multiplier;
    Dsp *= multiplier;
    D += Dsp;
}
