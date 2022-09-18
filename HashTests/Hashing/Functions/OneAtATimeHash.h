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
	// https://en.wikipedia.org/wiki/Jenkins_hash_function#one_at_a_time
	struct OneAtATimeHash
	{
		using hash_type = uint32_t;

		template<typename Type>
		hash_type operator()(const Type & object) const
		{
			return hash(object);
		}

		template<typename Type>
		static hash_type hash(const Type & object)
		{
			const auto pointer { reinterpret_cast<const unsigned char *>(&object) };
			
			hash_type hash { 0 };

			for(size_t index = 0; index < sizeof(Type); ++index)
			{
				hash += pointer[index];
				hash += (hash << 10);
				hash ^= (hash >> 6);
			}
			
			hash += (hash << 3);
			hash ^= (hash >> 11);
			hash += (hash << 15);
			
			return hash;
		}
	};
	
	// The version I originally used,
	// with the final three steps omitted.
	struct PartialOneAtATimeHash
	{
		using hash_type = uint32_t;

		template<typename Type>
		hash_type operator()(const Type & object) const
		{
			return hash(object);
		}

		template<typename Type>
		static hash_type hash(const Type & object)
		{
			const auto pointer { reinterpret_cast<const unsigned char *>(&object) };
			
			hash_type hash { 0 };

			for(size_t index = 0; index < sizeof(Type); ++index)
			{
				hash += pointer[index];
				hash += (hash << 10);
				hash ^= (hash >> 6);
			}
			
			return hash;
		}
	};
}