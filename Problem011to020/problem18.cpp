#include "stdafx.h"
#include "utils.h"

namespace
{
    const std::array<std::array<int, 16>, 15> Numbers = {{
        { 0, 75,                                                        },
        { 0, 95, 64,                                                    },
        { 0, 17, 47, 82,                                                },
        { 0, 18, 35, 87, 10,                                            },
        { 0, 20,  4, 82, 47, 65,                                        },
        { 0, 19,  1, 23, 75,  3, 34,                                    },
        { 0, 88,  2, 77, 73,  7, 63, 67,                                },
        { 0, 99, 65,  4, 28,  6, 16, 70, 92,                            },
        { 0, 41, 41, 26, 56, 83, 40, 80, 70, 33,                        },
        { 0, 41, 48, 72, 33, 47, 32, 37, 16, 94, 29,                    },
        { 0, 53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,                },
        { 0, 70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,            },
        { 0, 91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,        },
        { 0, 63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,    },
        { 0,  4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23 },
    }};

    template <size_t ROWS>
    int64_t GetMaximumSumOfTriangle(std::array<std::array<int, ROWS + 1>, ROWS> nums)
    {
        for (size_t r = 1; r < nums.size(); ++r)
        {
            for (size_t c = 1; c <= r + 1; ++c)
            {
                nums[r][c] += std::max(nums[r - 1][c - 1], nums[r - 1][c]);
            }
        }

        return *std::max_element(nums.back().begin(), nums.back().end());
    }
}

int64_t Problem18()
{
    return GetMaximumSumOfTriangle<15>(Numbers);
}
