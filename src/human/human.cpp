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
#include "human.h"
/*
* Constructer for human (crazy)
*/
Human::Human::Human(std::string name, Modifier* mods) {

	// Generate limbs
	Limb* head = new Limb("Head");
	limbs.push_back(head);

	Limb* LArm = new Limb("LEFT_Arm");
	limbs.push_back(LArm);

	Limb* RArm = new Limb("RIGHT_Arm");
	limbs.push_back(RArm);

	Limb* Torso = new Limb("Torso");
	limbs.push_back(Torso);

	Limb* LLeg = new Limb("LEFT_Leg");
	limbs.push_back(LLeg);

	Limb* RLeg = new Limb("RIGHT_Leg");
	limbs.push_back(RLeg);
}