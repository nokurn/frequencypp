// Copyright 2021-2022 Jeremiah Griffin
//
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
// OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

#include <frequencypp/frequency.hpp>

#include <catch2/catch.hpp>

#include <ratio>
#include <type_traits>

TEST_CASE("rep type alias is same as template argument", "[type]")
{
    using namespace ::frequencypp;

    REQUIRE(std::is_same_v<frequency<int>::rep, int>);
    REQUIRE(std::is_same_v<frequency<float>::rep, float>);
}

TEST_CASE("period type alias is same as template argument", "[type]")
{
    using namespace ::frequencypp;

    REQUIRE(std::ratio_equal_v<frequency<int>::period, std::ratio<1>>);
    REQUIRE(std::ratio_equal_v<frequency<int, std::ratio<2, 3>>::period, std::ratio<2, 3>>);
    REQUIRE(std::ratio_equal_v<frequency<int, std::ratio<4, 6>>::period, std::ratio<4, 6>>);
    REQUIRE(std::ratio_equal_v<frequency<int, std::ratio<4, 6>>::period, std::ratio<2, 3>>);
}
