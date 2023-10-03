//
//  solution.cpp
//  schemes
//
//  Created by Кирилл Дегтярев on 30.09.2023.
//

#include "solution.hpp"
#include <vector>

Solution::Solution(){}
Solution::Solution(std::vector<double> answer) : _answer(answer){}

void Solution::print_in_file(std::string filename)
{
    std::ofstream file("/Users/kirilldegtarev/Desktop/schemes/logs/"+filename+".txt");
    for ( auto element : _answer) 
        {
            std::cout<<element<<std::endl;
            file << element << ' ';
        }
    file.close();
    
    std::cout<<"data in file"<<std::endl;
    
}
