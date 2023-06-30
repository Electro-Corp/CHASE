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

#include <plog/Log.h>
#include <plog/Initializers/RollingFileInitializer.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Initializers/ConsoleInitializer.h>

#include "chase.h"


#define MAJOR_VER_NUM 0
#define MINOR_VER_NUM 0

/*
 * The init function does something pretty wack. It inits (most helpful program comment)
 * 
 * but really it does:
 *  > Thread manager inits
 *  > Enviorment setup
*/

void Chase::init(int groupThreadInitNums) {


	plog::init<plog::TxtFormatter>(plog::debug, plog::streamStdOut);

	PLOG_DEBUG << "Chase Init - Version " << MAJOR_VER_NUM << "." << MINOR_VER_NUM;

	// Initilize thread manager
	Chase::threadMan = new ThreadManager::ThreadManager(groupThreadInitNums);
}