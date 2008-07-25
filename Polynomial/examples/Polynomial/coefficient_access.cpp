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
  
  PT_2::Get_coefficient get_coefficient;
  std::cout << "Coefficient of y^0: "<< get_coefficient(F,0) << std::endl;
  std::cout << "Coefficient of y^1: "<< get_coefficient(F,1) << std::endl;
  std::cout << "Coefficient of y^2: "<< get_coefficient(F,2) << std::endl;
  std::cout << "Coefficient of y^3: "<< get_coefficient(F,3) << std::endl;
  std::cout << "Coefficient of y^4: "<< get_coefficient(F,4) << std::endl;
  std::cout << "Coefficient of y^5: "<< get_coefficient(F,5) << "\n"<< std::endl;
  
  PT_2::Leading_coefficient lcoeff;
  std::cout << "Leading coefficient with resepct to y:           "
            << lcoeff(F) << std::endl;

  PT_2::Get_innermost_coefficient get_icoeff;
  CGAL:: Exponent_vector ev(2,0); ev[0]=1; ev[1]=4;
  std::cout << "Innermost coefficient of monomial x^1y^4:        "
            << get_icoeff(F,ev) << std::endl;
  
  PT_2::Innermost_leading_coefficient ilcoeff;
  std::cout << "Innermost leading coefficient with resepct to y: "
            << ilcoeff(F) << std::endl; 
}
