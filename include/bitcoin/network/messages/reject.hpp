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
#ifndef LIBBITCOIN_NETWORK_MESSAGES_REJECT_HPP
#define LIBBITCOIN_NETWORK_MESSAGES_REJECT_HPP

#include <memory>
#include <bitcoin/system.hpp>
#include <bitcoin/network/define.hpp>
#include <bitcoin/network/messages/enums/identifier.hpp>

namespace libbitcoin {
namespace network {
namespace messages {

struct BCT_API reject
{
    typedef std::shared_ptr<const reject> cptr;

    enum class reason_code: uint8_t
    {
        /// The reason code is not defined.
        undefined = 0x00,

        /// The message was malformed.
        malformed = 0x01,

        /// In response to block or tx message: invalid (data is hash).
        invalid = 0x10,

        /// In response to version message: version.
        /// In respose to block message: version (data is hash).
        obsolete = 0x11,

        /// In respose to tx message: double spend (data is hash).
        /// In respose to version message: more than one received.
        duplicate = 0x12,

        /// In respose to tx message: nonstandard (data is hash).
        nonstandard = 0x40,

        /// In respose to tx message: dust output(s) (data is hash).
        dust = 0x41,

        /// In respose to tx message: insufficient fee (data is hash).
        insufficient_fee = 0x42,

        /// In response to block message: failed checkpoint (data is hash).
        checkpoint = 0x43
    };

    static const identifier id;
    static const std::string command;
    static const uint32_t version_minimum;
    static const uint32_t version_maximum;

    static uint8_t reason_to_byte(reason_code value) NOEXCEPT;
    static reason_code byte_to_reason(uint8_t value) NOEXCEPT;

    static cptr deserialize(uint32_t version,
        const system::data_chunk& data) NOEXCEPT;
    static reject deserialize(uint32_t version,
        system::reader& source) NOEXCEPT;

    bool serialize(uint32_t version,
        const system::data_slab& data) const NOEXCEPT;
    void serialize(uint32_t version,
        system::writer& sink) const NOEXCEPT;

    size_t size(uint32_t version) const NOEXCEPT;

    std::string message;
    reason_code code;
    std::string reason;
    system::hash_digest hash;

protected:
    static bool is_chain(const std::string& message) NOEXCEPT;
};

} // namespace messages
} // namespace network
} // namespace libbitcoin

#endif
