#include "main.h"

#include <iostream>

#include "test.hpp"

void initializeMod(goManager* gom)
{
    gom->go_vector.push_back(new test());
}