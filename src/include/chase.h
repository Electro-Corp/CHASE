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
#ifndef CHASE_H
#define CHASE_H

#define DEBUG 1


#ifdef CHASELibrary_EXPORTS
	#define CHAPI __declspec(dllexport)
#else
	#define CHAPI __declspec(dllimport)
#endif

// Includes
#include <threadmanager/threadmanager.h>
#include <enviorment/enviorment.h>

namespace Chase {
	ThreadManager::ThreadManager* threadMan;
	Enviorment::Enviorment* env;

	// Windows
	#ifdef WIN32
	#ifdef __cplusplus
	extern "C" {
	#endif
		// Start exported functions

		CHAPI void init();

		CHAPI Human::human_id addHuman(std::string name);


		// Debug funcs
#ifdef DEBUG
		CHAPI std::string _debugGetName(Human::human_id id);
#endif

		// End exported functions
	#ifdef __cplusplus
	}
	#endif
	#else
		void init();
		Human::human_id addHuman(std::string name);
		
		// debug
		#ifdef DEBUG
		std::string _debugGetName(Human::human_id id);
		#endif
	#endif
	 
}
#endif