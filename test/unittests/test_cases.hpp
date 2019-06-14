// intx: extended precision integer library.
// Copyright 2019 Pawel Bylica.
// Licensed under the Apache License, Version 2.0.

#pragma once

#include <intx/intx.hpp>

namespace
{
using namespace intx;

struct arithmetic_test_case
{
    intx::uint256 x;
    intx::uint256 y;
    intx::uint256 sum;
    intx::uint256 product;
};

constexpr auto M = ~uint64_t(0);

arithmetic_test_case arithmetic_test_cases[] = {
    {0, 0, 0, 0},
    {127, 1, 128, 127},
    {1, 1, 2, 1},
    {{{1, 1}, {1, 1}}, {{1, 1}, {1, 1}}, {{2, 2}, {2, 2}}, {{4, 3}, {2, 1}}},
    {{{1, 1}, {1, M}}, {{1, 1}, {1, 1}}, {{2, 2}, {3, 0}}, {{3, 2}, {0, M}}},
    {{{1, 1}, {M, 1}}, {{1, 1}, {1, 1}}, {{2, 3}, {0, 2}}, {{3, 2}, {0, 1}}},
    {{{1, M}, {1, 1}}, {{1, 1}, {1, 1}}, {{3, 0}, {2, 2}}, {{3, 1}, {2, 1}}},
    {{{M, 1}, {1, 1}}, {{1, 1}, {1, 1}}, {{0, 2}, {2, 2}}, {{2, 3}, {2, 1}}},
    {
        0xffffffffffffff00feffff42000000767606000000000007ffffffffffffffff_u256,
        0xffff000000000000000000000000000000000000000000032b00000000008000_u256,
        0xfffeffffffffff00feffff4200000076760600000000000b2b00000000007fff_u256,
        0x27d5fda6158080f747860200003b3b1c580000000003fffcd4ffffffffff8000_u256,
    },
    {
        0x01000000000000000000030000000000000000000000000002000000000000ff_u256,
        0x0000000000000000000002000000000000ffffffffffffffffffffffffff0000_u256,
        0x01000000000000000000050000000000010000000000000001ffffffffff00ff_u256,
        0x00000003fffffffffd03fe0000000000fefffffffffffdffffffffffff010000_u256,
    },
    {
        0xffffffff000000ffffffffffffffffffffffffffffffffffffff81002f000000_u256,
        0x00000000000000000000000000ffffffffffffffffffffffffffffffffffb0ff_u256,
        0xffffffff000001000000000000ffffffffffffffffffffffffff81002effb0ff_u256,
        0x00004f00ffb0fe81002f00000000000000000000000000002731707ed1000000_u256,
    },
};
}  // namespace
