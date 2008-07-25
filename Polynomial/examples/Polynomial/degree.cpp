#include <CGAL/basic.h>
#include <CGAL/Polynomial.h>
#include <CGAL/Polynomial_traits_d.h>
#include <CGAL/Polynomial_type_generator.h>
#include <CGAL/Gmpz.h>

int main(){
  CGAL::set_pretty_mode(std::cout);
  typedef CGAL::Polynomial_type_generator<CGAL::Gmpz,2>::Type Poly_int_2;
  typedef CGAL::Polynomial_traits_d<Poly_int_2>            PT_2;
  typedef PT_2::Coefficient                                Poly_int_1;
  typedef PT_2::Innermost_coefficient                      Integer; 
  
  //construction using shift 
  Poly_int_2 x = PT_2::Shift()(Poly_int_2(1),1,0); // shift 1 by x_0^1
  Poly_int_2 y = PT_2::Shift()(Poly_int_2(1),1,1); // shift 1 by x_1^1
  
  Poly_int_2 F 
    = 11 * CGAL::ipower(y,4) * CGAL::ipower(x,2) 
    + 5 * CGAL::ipower(y,4)  * CGAL::ipower(x,1) 
    + 7 * CGAL::ipower(y,3)  * CGAL::ipower(x,2);  
  std::cout << "The bivariate polynomial F: " << F <<"\n"<< std::endl;
  
  PT_2::Degree degree; 
  PT_2::Total_degree total_degree; 
  PT_2::Degree_vector degree_vector;
  
  std::cout << "The degree of F with respect to y: "<< degree(F) <<std::endl;
  std::cout << "The degree of F with respect to x: "<< degree(F,0) <<std::endl;
  std::cout << "The total degree of F            : "<< total_degree(F) <<std::endl;
  std::cout << "The degree vector of F           : "<< degree_vector(F) <<std::endl;
  
  
  
}
