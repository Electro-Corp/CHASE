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
#ifndef HUMAN_H
#define HUMAN_H

#include <human/limb.h>
#include <human/modifiers.h>

#include <object.hpp>

#include <vector>
#include <string>


namespace Human {
	typedef struct {
		int loc, sub_loc;
	} human_id;

	class Human : public Object {
	private:
		/*
		* Basic Human stats
		*/
		std::string name;
		float age;

		Modifier* mods;
		human_id id;
		// Limbs
		std::vector<Limb*> limbs;
	public:
		Human(std::string name, human_id id);
		std::string get_name();
		human_id get_id();

		// 'void' is tmp, change it to some return data
		void humanMainUpdate(/*ARGS NEEDED*/);
	};
}
#endif