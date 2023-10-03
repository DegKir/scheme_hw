//
//  solution.hpp
//  schemes
//
//  Created by Кирилл Дегтярев on 30.09.2023.
//
#pragma once

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

class Solution
{
    std::vector<double> _calculation_data;
    std::vector<double> _answer;
    double _calculation_time;

public:
    Solution();
    Solution(std::vector<double> answer);
//    Solution(std::vector<double> answer, std::vector<double> calculation_data, unsigned int calculation_time);
//    Solution(std::vector<double> answer, unsigned int calculation_time);
//    Solution(std::vector<double> answer);
    
    void print_in_file(std::string filename = "output.txt");
    
};
