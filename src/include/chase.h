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

	#ifdef __cplusplus
	extern "C" {
	#endif
		// Start exported functions

		CHAPI void init();

		// End exported functions
	#ifdef __cplusplus
	}
	#endif
	 
}
#endif