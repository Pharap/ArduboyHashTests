#pragma once

//
//  Copyright (C) 2022 Pharap (@Pharap)
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

// For uint32_t
#include <stdint.h>

namespace Hashing
{
	// https://en.wikipedia.org/wiki/Fletcher%27s_checksum#Straightforward
	template<uint16_t modulus>
	struct Fletcher16Modulo
	{
		using hash_type = uint16_t;

		template<typename Type>
		hash_type operator()(const Type & object) const
		{
			return hash(object);
		}

		template<typename Type>
		static hash_type hash(const Type & object)
		{
			const auto pointer { reinterpret_cast<const unsigned char *>(&object) };

			uint16_t low { 0 };
			uint16_t high { 0 };

			for(size_t index = 0; index < sizeof(Type); ++index)
			{
				low = ((low + pointer[index]) % modulus);
				high = ((low + high) % modulus);
			}
			
			return ((high << 8) | (low << 0));
		}
	};

	// https://en.wikipedia.org/wiki/Fletcher%27s_checksum#Caution_on_Modulus
	struct Fletcher16
	{
		using hash_type = uint16_t;

		template<typename Type>
		hash_type operator()(const Type & object) const
		{
			return hash(object);
		}

		template<typename Type>
		static hash_type hash(const Type & object)
		{
			const auto pointer { reinterpret_cast<const unsigned char *>(&object) };

			uint16_t low { 0 };
			uint16_t high { 0 };

			for(size_t index = 0; index < sizeof(Type); ++index)
			{
				low = (low + pointer[index]);
				high = (low + high);
			}
			
			return ((high << 8) | (low << 0));
		}
	};
}