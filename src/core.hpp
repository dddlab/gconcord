template <typename Derived>
void myfunc(Eigen::MatrixBase<Derived>& b, double multiplier){
    b *= multiplier;
}