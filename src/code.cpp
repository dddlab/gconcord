#include <RcppEigen.h>
#include "core.hpp"

// #include <Rcpp.h>
// using namespace Rcpp;

// [[Rcpp::depends(RcppEigen)]]

//' Multiply a number by two
//' 
//' @param x A single integer.
//' @export
// [[Rcpp::export]]
void myfunc_wrapper(Eigen::Map<Eigen::MatrixXd> M, double multiplier){
    myfunc(M, multiplier);
}

//' Multiply a number by two
//' 
//' @param x A single integer.
//' @param y *A* *single* integer.
//' @export
// [[Rcpp::export]]
double qwer(double x, double y){
    return(x + y);
}