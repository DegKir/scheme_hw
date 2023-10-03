//
//  main.cpp
//  conservative test
//
//  Created by Кирилл Дегтярев on 01.10.2023.
//

#include <iostream>
#include "operators_generators.hpp"
#include "scheme.hpp"
#include "solution.hpp"
int main(int argc, const char * argv[]) {
    std::cout<<"naive conservative test"<<std::endl;
    
    unsigned int mesh_size = 100;
    std::vector<double> a(mesh_size), b(mesh_size), d(mesh_size), phi(mesh_size);
    double g1 = 1, g2 = 0, Length=1, dx = Length/(mesh_size-1);
    
    //x_0 is some number around 0.3 and k1, k2 is just some numbers
    double x_0 = 0.3;
    double k1 = 1, k2 = 2;

    for(int i = 0; i < mesh_size; i++)
    {
        if(dx*(i+1) <= x_0)
        {
            a[i]=k1;
            b[i]=k1;
        }
        if(dx*(i-1) >= x_0)
        {
            a[i]=k2;
            b[i]=k2;
        }
        if(dx*i<=x_0 && x_0<=dx*(i+1))
        {
            a[i]=k1;
            b[i]=dx/((x_0-dx*i)/k1+(dx*(i+1)-x_0)/k2);
        }
        if(dx*(i-1)<= x_0 && x_0 <= dx*i)
        {
            a[i]=dx/((x_0-dx*(i-1))/k1+(dx*i-x_0)/k2);
            b[i]=k2;
        }
        d[i]=0;
        phi[0]=0;
    }

    std::vector<std::vector<double> > scheme_operator = get_conservative_heat_operator(a, b, d, phi, g1, g2, mesh_size, Length);
    std::vector<double> right_part = get_conservative_heat_right_part(a, b, d, phi, g1, g2, mesh_size, Length);
    
    TridiagonalScheme main_scheme(scheme_operator, right_part);
    auto solution = main_scheme.solve();
    solution.print_in_file("conservative_test");
    std::cout << "END"<<std::endl;
    return 0;
}
