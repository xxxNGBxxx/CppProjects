#include "erase.h"

VErase::VErase(){}

std::vector<int> VErase::operator()(const std::vector<int> &v){
    std::vector<int> m_v;
        for(auto& i : v){
            if(i % 2 == 0){
                m_v.push_back(i);
            }
        }
    return m_v;
}

