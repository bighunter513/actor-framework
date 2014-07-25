/******************************************************************************
 *                       ____    _    _____                                   *
 *                      / ___|  / \  |  ___|    C++                           *
 *                     | |     / _ \ | |_       Actor                         *
 *                     | |___ / ___ \|  _|      Framework                     *
 *                      \____/_/   \_|_|                                      *
 *                                                                            *
 * Copyright (C) 2011 - 2014                                                  *
 * Dominik Charousset <dominik.charousset (at) haw-hamburg.de>                *
 *                                                                            *
 * Distributed under the terms and conditions of the BSD 3-Clause License or  *
 * (at your option) under the terms and conditions of the Boost Software      *
 * License 1.0. See accompanying files LICENSE and LICENCE_ALTERNATIVE.       *
 *                                                                            *
 * If you did not receive a copy of the license files, see                    *
 * http://opensource.org/licenses/BSD-3-Clause and                            *
 * http://www.boost.org/LICENSE_1_0.txt.                                      *
 ******************************************************************************/

#ifndef TIMEOUT_DEFINITION_HPP
#define TIMEOUT_DEFINITION_HPP

#include <functional>

#include "caf/duration.hpp"

namespace caf {

namespace detail {
class behavior_impl;
}

template <class F>
struct timeout_definition {
  static constexpr bool may_have_timeout = true;
  duration timeout;
  F handler;
  detail::behavior_impl* as_behavior_impl() const;

};

using generic_timeout_definition = timeout_definition<std::function<void()>>;

} // namespace caf

#endif // TIMEOUT_DEFINITION_HPP