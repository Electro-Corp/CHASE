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
#include <pch.h>
#include <human/human.h>
#include <iostream>
/*
* Constructer for human (crazy)
*/
Human::Human::Human(std::string name, human_id id) : Object() { // extends from object (this says a lot about society)
	// Basic setup
	this->name = name;
	this->id = id;

	// Generate limbs
	Limb* head = new Limb("Head");
	limbs.push_back(head);

	Limb* LArm = new Limb("LEFT_Arm");
	limbs.push_back(LArm);
	lArm = true;

	Limb* RArm = new Limb("RIGHT_Arm");
	limbs.push_back(RArm);
	rArm = true;

	Limb* Torso = new Limb("Torso");
	limbs.push_back(Torso);

	Limb* LLeg = new Limb("LEFT_Leg");
	limbs.push_back(LLeg);
	lLeg = true;

	Limb* RLeg = new Limb("RIGHT_Leg");
	limbs.push_back(RLeg);
	rLeg = true;

	functioningLimbs = limbs.size();

	// Generate modifiers

}

std::string Human::Human::get_name() {
	return this->name;
}

Human::human_id Human::Human::get_id() {
	return this->id;
}

/*
* Unfinished, change void to some return 
* data in the future
* 
* == Notes on mainUpdate
* > It is the full update cycle, meaning that it 
* looks at the FULL viewable enviorment
*/
void Human::Human::humanMainUpdate(/*ARGS NEEDED*/) {
	float survivabilityProbability; // 0.0f - 100.0f (it could be 0.0f to 1.0f, but i feel like 100.0f is more... uhhhh... better

	/*
	* General algorithim structure
	*/

	/*
	* Use some function in Transform to get all objects visible
	*/

	// 
	/*
	* Different types of objects have 
	* different modifers/types
	* 
	* > Human
	*	> Check for if on self or enemys team, then jump to some
	*	  sub routine relating to that
	* > Cover
	*	> Calculate if self should jump to cover
	* > Other
	*	> add more as time goes on
	*/


	// First check health of all limbs
	// Could be done with an average i guess
	// But it's probabbly better to check each 
	// so we can determin what actions can be taken



	// TODO: MAKE THE VALUES getDamage
	// IS COMPARED WITH READ FROM A 
	// CONFIG FILE

	// in order:
	// 1. head
	if(limbs[0]->getDamage() > 50.0f){
		// We're pretty damaged, just lie around
		return; // once again this will return some value
	}
	// 2. l_arm
	if(lArm){
		if(limbs[0]->getDamage() > 90.0f){
			functioningLimbs--;
			lArm = false;
		}else if(limbs[0]->getDamage() > 70.0f){
			
		}
	}
	// 3. h_arm



	// SUBS

	/*
	*	HUMAN_SELF_TEAM
	*/

	// idk

	/*
	*	HUMAN_ENEMY_TEAM
	*/

	// Calculate probability
	// of surviving an encounter
	// decide from there
}