#include <iostream>
#include <RcppEigen.h>
#include "core.hpp"

typedef Eigen::MappedSparseMatrix< double > MappedSparseMatrix ;
typedef Eigen::Map< Eigen::MatrixXd > MappedMatrix ;

// [[Rcpp::depends(RcppEigen)]]

//' Mapping R matrix  
//' 
//' @param x A single integer.
//' @export
// [[Rcpp::export]]
void wrapper_1(
    Eigen::Map<Eigen::MatrixXd> M, 
    double multiplier)
{
    myfunc(M, multiplier);
}

//' wrapper 2
//' 
//' @param x A single integer.
//' @export
// [[Rcpp::export]]
void wrapper_2(
    Rcpp::NumericMatrix Ms, 
    double multiplier)
{
    Eigen::Map<Eigen::MatrixXd> M(Rcpp::as<Eigen::Map<Eigen::MatrixXd> >(Ms));
    myfunc(M, multiplier);
}


//' wrapper 3
//' 
//' @param x A single integer.
//' @export
// [[Rcpp::export]]
double wrapper_3(
    Eigen::Map<Eigen::SparseMatrix<double> > M, 
    double multiplier)
{
    M *= multiplier;
    return(M.sum());
}

//' Does not modify input matrix
//' @export
// [[Rcpp::export]]
Eigen::SparseMatrix<double> wrapper_4(
    const Eigen::Map<Eigen::MatrixXd> M, 
    double multiplier)
{
    Eigen::SparseMatrix<double> Msp = M.sparseView();
    Msp *= multiplier;
    return(Msp);
}

//' Does not modify input matrix
//' @export
// [[Rcpp::export]]
void wrapper_5(
    Eigen::Map<Eigen::MatrixXd> M, 
    Eigen::Map<Eigen::SparseMatrix<double> > Msp,
    double multiplier)
{
    myfunc_complex(M, Msp, multiplier);
}