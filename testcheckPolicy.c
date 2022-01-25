

#include "types.h"
#include "stat.h"
#include "user.h"


int main(int argc, char const *argv[])
{

    setPolicy(2);
    checkPolicy();

    return 0;
}
