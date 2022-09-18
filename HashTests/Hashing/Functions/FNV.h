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
	template<typename Integer, Integer offsetBasisValue, Integer primeValue>
	struct FNV1
	{
		using hash_type = Integer;

		static constexpr hash_type offset_basis { offsetBasisValue };
		static constexpr hash_type prime { primeValue };

		template<typename Type>
		hash_type operator()(const Type & object) const
		{
			return hash(object);
		}

		template<typename Type>
		static hash_type hash(const Type & object)
		{
			const auto pointer { reinterpret_cast<const unsigned char *>(&object) };
			
			hash_type hash { offset_basis };

			for(size_t index = 0; index < sizeof(Type); ++index)
				hash = ((hash * prime) ^ pointer[index]);
			
			return hash;
		}
	};

	using FNV32 = FNV1<uint32_t, 2166136261, 16777619>;

	template<typename Integer, Integer offsetBasisValue, Integer primeValue>
	struct FNV1a
	{
		using hash_type = Integer;

		static constexpr hash_type offset_basis { offsetBasisValue };
		static constexpr hash_type prime { primeValue };

		template<typename Type>
		hash_type operator()(const Type & object) const
		{
			return hash(object);
		}

		template<typename Type>
		static hash_type hash(const Type & object)
		{
			const auto pointer { reinterpret_cast<const unsigned char *>(&object) };
			
			hash_type hash { offset_basis };

			for(size_t index = 0; index < sizeof(Type); ++index)
				hash = ((hash ^ pointer[index]) * prime);
			
			return hash;
		}
	};

	using FNV32a = FNV1a<uint32_t, 2166136261, 16777619>;
}