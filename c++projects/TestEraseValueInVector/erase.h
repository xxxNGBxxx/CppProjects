#ifndef H8_H
#define H8_H
#include <vector>

class VErase{
public:
    VErase();
    std::vector<int> operator()(const std::vector<int> &v);
};

#endif // H8_H
