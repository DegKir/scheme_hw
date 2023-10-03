//
//  scheme.hpp  
//  schemes
//
//  Created by Кирилл Дегтярев on 30.09.2023.
//
#pragma once

#include"solution.hpp"
#include <string.h>

class TridiagonalScheme
{
public:
    TridiagonalScheme(std::vector<std::vector<double> > scheme_operator, std::vector<double> right_part);
    
    std::vector<std::vector<double> > _scheme_operator;
    std::vector<double> _right_part;
    
    
    Solution solve() const;
    ~TridiagonalScheme() {};
};
