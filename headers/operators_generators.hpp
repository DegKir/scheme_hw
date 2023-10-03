//
//  operators_generators.hpp
//  schemes
//
//  Created by Кирилл Дегтярев on 01.10.2023.
//
#pragma once
#include<vector>

std::vector<std::vector<double> > get_linear_heat_operator(std::vector<double> k, std::vector<double> q, std::vector<double> f, double g1, double g2, int mesh_size, double Lenght);

std::vector<double> get_linear_heat_right_part(std::vector<double> k, std::vector<double> q, std::vector<double> f, double g1, double g2, int mesh_size, double Lenght);

std::vector<std::vector<double> > get_conservative_heat_operator(std::vector<double> a, std::vector<double> b, std::vector<double> d, std::vector<double> phi, double g1, double g2, int mesh_size, double Lenght);

std::vector<double> get_conservative_heat_right_part(std::vector<double> a, std::vector<double> b, std::vector<double> d, std::vector<double> phi, double g1, double g2, int mesh_size, double Lenght);

