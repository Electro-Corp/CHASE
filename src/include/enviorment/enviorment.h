/*
 * Copyright 2023 Electro Corparation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ENVIORMENT_H
#define ENVIORMENT_H

#include <vector>
#include <transform/transform.h>
#include <../include/object.hpp>

namespace Enviorment {
	/*
	* Contains a single sub-area of the Environment
	*/

	class Source {
	private:
		std::vector<Transform::Point> vertices;
	public:
		template<typename... Args>
		Source(Transform::Point val, Args... args);

		// Getter and setter
		std::vector<Transform::Point> getVertices();
	};

	/*
	* Contains the current enviorment
	*/
	class Enviorment {
	private:
		std::vector<Object> objects;
		std::vector<Source> regions;
	public:
		Enviorment();

		// Create sources
		void addSource(Source src);
		
		// Getters and setters

		
	};

	
}
#endif