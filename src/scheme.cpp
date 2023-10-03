//
//  scheme.cpp
//  schemes
//
//  Created by Кирилл Дегтярев on 30.09.2023.
//

#include "scheme.hpp"
#include "solution.hpp"
#include <string>
#include <iostream>
#include <vector>

TridiagonalScheme::TridiagonalScheme(std::vector<std::vector<double> > scheme_operator, std::vector<double> right_part) : _scheme_operator(scheme_operator), _right_part(right_part)
{
    std::cout<<"scheme created"<<std::endl;
}

Solution TridiagonalScheme::solve() const
{
    std::vector<double> a = _scheme_operator[0];
    std::vector<double> b = _scheme_operator[1];
    std::vector<double> c = _scheme_operator[2];
    std::vector<double> d = _right_part;
        
    int n = b.size();
    std::vector<double> x(n);
    std::vector<double> c_star(n-1);
    std::vector<double> d_star(n);

    c_star[0] = c[0]/b[0];
    d_star[0] = d[0]/b[0];
    for (int i = 1; i < n-1; i++) {
        c_star[i] = c[i]/(b[i]-a[i-1]*c_star[i-1]);
    }
    
    for (int i = 1; i < n; i++) {
        d_star[i] = (d[i] - d_star[i-1]*a[i-1])/(b[i]-c_star[i-1]*a[i-1]);
    }

    x[n-1] = d_star[n-1];
    for (int i = n - 2; i >= 0; i--)
    {
        x[i]=(d_star[i]-c_star[i]*x[i+1]);
    }
    
    std::cout<<"answer calculated"<<std::endl;
    return x;
}
