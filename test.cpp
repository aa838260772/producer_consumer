#include "Factory.h"
#include <iostream>
using namespace std;

int main(int argc, const char *argv[])
{
    Factory fac(5, 2, 1);
    fac.start();
    return 0;
}
