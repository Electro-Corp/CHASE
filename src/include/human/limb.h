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
#ifndef LIMB_H
#define LIMB_H

#include <string>

/*
* Each human has limbs that detemine
* what it does. If both of its arms
* are destroyed, chances are it will
* run away instead of fighting.
*/


class Limb {
private:
	float damage; // float value from 0.0 to 1.0 (1.0 means completely useless/dismembered)

	std::string name;
public:
	Limb(std::string name);
};
#endif