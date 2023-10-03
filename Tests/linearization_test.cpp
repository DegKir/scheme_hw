//
//  main.cpp
//  naive_heat_test
//
//  Created by Кирилл Дегтярев on 30.09.2023.
//

#include <iostream>
#include "operators_generators.hpp"
#include "scheme.hpp"
#include "solution.hpp"

int main(int argc, const char * argv[]) {
    std::cout<<"naive linearization test"<<std::endl;
    unsigned int mesh_size = 100;
    std::vector<double> k(mesh_size), q(mesh_size), f(mesh_size);
    double g1 = 1, g2 = 0.5, Length=1, dx = Length/(mesh_size-1);
    
    //filling vectors for k,q,f functions
    auto k_function = [](double x){return 1+x*x;};
    //auto k_function = [](double x){return 1;};
    auto q_function = [](double x){return 0;};
    auto f_function = [](double x){return 2*x;};
    //auto f_function = [](double x){return 1;};
    
    for(int i = 0; i < mesh_size; i++)
    {
        k[i] = k_function(dx*i);
        //std::cout<<"k["<<i<<"] = "<<k[i]<<std::endl;
        q[i] = q_function(dx*i);
        //std::cout<<"q["<<i<<"] = "<<q[i]<<std::endl;
        f[i] = f_function(dx*i);
        //std::cout<<"f["<<i<<"] = "<<f[i]<<std::endl;
    }
    
    std::vector<std::vector<double>> scheme_operator = get_linear_heat_operator(k, q, f, g1, g2, mesh_size, Length);
    std::vector<double> right_part = get_linear_heat_right_part(k, q, f, g1, g2, mesh_size, Length);
    
    TridiagonalScheme main_scheme(scheme_operator, right_part);
    auto solution = main_scheme.solve();
    solution.print_in_file("naive_linearization_    test");
    std::cout << "END"<<std::endl;
    
    return 0;
}
