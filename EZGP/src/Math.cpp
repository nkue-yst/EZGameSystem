/**
 * @author Yoshito Nakaue
 * @date 2020/09/08
 */

#include <EZGP/Math.hpp>
#include <random>

namespace ezgp
{
    int RandomInt(int min, int max)
    {
        std::random_device seed_gen;
        std::mt19937_64 engine(seed_gen());
        std::uniform_int_distribution<int64_t> rand(min, max);
        return static_cast<int>(rand(engine));
    }
}
