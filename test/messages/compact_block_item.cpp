/**
 * Copyright (c) 2011-2023 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "../test.hpp"

BOOST_AUTO_TEST_SUITE(compact_block_item_tests)

using namespace bc::network::messages;

BOOST_AUTO_TEST_CASE(compact_block_item__size__default__expected)
{
    constexpr auto expected = sizeof(uint64_t);
    BOOST_REQUIRE_EQUAL(compact_block_item{}.size(level::canonical, true), expected);
    BOOST_REQUIRE_EQUAL(compact_block_item{}.size(level::canonical, false), expected);
}

BOOST_AUTO_TEST_SUITE_END()
