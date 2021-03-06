// intx: extended precision integer library.
// Copyright 2019-2020 Pawel Bylica.
// Licensed under the Apache License, Version 2.0.
#pragma once

#include <intx/intx.hpp>

namespace intx
{
namespace experimental
{
uint256 add_recursive(const uint256& a, const uint256& b) noexcept;
uint256 add_waterflow(const uint256& a, const uint256& b) noexcept;
}  // namespace experimental
}  // namespace intx
