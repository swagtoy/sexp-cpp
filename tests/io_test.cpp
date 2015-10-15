// SExp - A S-Expression Parser for C++
// Copyright (C) 2015 Ingo Ruhnke <grumbel@gmail.com>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <gtest/gtest.h>

#include <sstream>

#include "sexp/io.hpp"
#include "sexp/value.hpp"
#include "sexp/parser.hpp"

TEST(IOTest, roundtrip)
{
  std::vector<std::string> data{"()",
      "(1 2.5 foo \"TEXT\" bar bar)",
      "(1 0.25 foobar)",
      "((1) (0.25) (foobar))",
      "((1 ()) ((0.25)) (1 . 5) (foobar))",
      };

  for(auto const& text : data)
  {
    EXPECT_EQ(text, sexp::Parser::from_string(text).str());
  }
}

/* EOF */
