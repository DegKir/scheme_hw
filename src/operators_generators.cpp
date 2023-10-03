//
//  operators_generators.cpp
//  schemes
//
//  Created by Кирилл Дегтярев on 01.10.2023.
//

#include"operators_generators.hpp"
#include<vector>
#include<iostream>

std::vector<std::vector<double> > get_linear_heat_operator(std::vector<double> k, std::vector<double> q, std::vector<double> f, double g1, double g2, int mesh_size, double Lenght)
{
    double h = Lenght/(mesh_size-1);
    
    std::vector<std::vector<double> > tridiagonal_data;
    tridiagonal_data.push_back(std::vector<double>(mesh_size-3, 0));
    tridiagonal_data.push_back(std::vector<double>(mesh_size-2, 0));
    tridiagonal_data.push_back(std::vector<double>(mesh_size-3, 0));

    //diagonal elements
    for(int i = 1; i < mesh_size-1; i++)
    {
        tridiagonal_data[1][i-1]=-2*k[i]/h/h-q[i];
    }
    
    //underdiagonal elements
    for(int i = 2; i < mesh_size - 1; i++)
    {
        tridiagonal_data[0][i-2]=k[i]/h/h-(k[i+1]-k[i-1])/4/h/h;
    }

    //overdiagonal elements
    for(int i = 1; i < mesh_size-2; i++)
    {
        tridiagonal_data[2][i-1]=k[i]/h/h+(k[i+1]-k[i-1])/4/h/h;
    }
    
    return tridiagonal_data;
}

std::vector<double> get_linear_heat_right_part(std::vector<double> k, std::vector<double> q, std::vector<double> f, double g1, double g2, int mesh_size, double Lenght)
{
    double h = Lenght/(mesh_size-1);
    std::vector<double> f_vector(mesh_size-2,0);
    
    for(int i = 1; i < mesh_size-1; i++)
    {
        f_vector[i-1] = -1*f[i];
    }
    
    f_vector[0] += -g1*(k[1]/h/h-(k[2]-k[0])/4/h/h);
    f_vector[f_vector.size()-1] += -g2*(k[k.size()-2]/h/h+(k[k.size()-1]-k[k.size()-3])/4/h/h);
    
    return f_vector;
}

std::vector<std::vector<double> > get_conservative_heat_operator(std::vector<double> a, std::vector<double> b, std::vector<double> d, std::vector<double> phi, double g1, double g2, int mesh_size, double Lenght)
{
    double h = Lenght/(mesh_size-1);
    
    std::vector<std::vector<double> > tridiagonal_data;
    tridiagonal_data.push_back(std::vector<double>(mesh_size-3, 0));
    tridiagonal_data.push_back(std::vector<double>(mesh_size-2, 0));
    tridiagonal_data.push_back(std::vector<double>(mesh_size-3, 0));

    //diagonal elements
    for(int i = 1; i < mesh_size-1; i++)
    {
        tridiagonal_data[1][i-1]=-(a[i]+b[i])/h/h-d[i];
    }
    
    //underdiagonal elements
    for(int i = 2; i < mesh_size - 1; i++)
    {
        tridiagonal_data[0][i-2]=a[i]/h/h;
    }

    //overdiagonal elements
    for(int i = 1; i < mesh_size-2; i++)
    {
        tridiagonal_data[2][i-1]=b[i]/h/h;
    }
    
    return tridiagonal_data;
}


std::vector<double> get_conservative_heat_right_part(std::vector<double> a, std::vector<double> b, std::vector<double> d, std::vector<double> phi, double g1, double g2, int mesh_size, double Lenght)
{
    double h = Lenght/(mesh_size-1);
    std::vector<double> phi_vector(mesh_size-2,0);
    
    for(int i = 1; i < mesh_size-1; i++)
    {
        phi_vector[i-1] = -1*phi[i];
    }
    
    phi_vector[0] += -g1*a[0]/h/h;
    phi_vector[phi_vector.size()-1] += -g2*b[b.size()-1]/h/h;
    
    return phi_vector;
}
