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

#include <threadmanager/threadmanager.h>

#include <plog/Log.h>
#include <plog/Initializers/RollingFileInitializer.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Initializers/ConsoleInitializer.h>

/*
* Thread Manager
*/


ThreadManager::ThreadManager::ThreadManager(int groupThreadInitNums) {
	PLOG_DEBUG << "Electro ThreadManager Startup";
	PLOG_DEBUG << "Creating GroupThreads...";

	// init group threads. Uses a vector to store all of them.
	// init allocation size is defined by the program.
	for (int i = 0; i < groupThreadInitNums; i++) {
		PLOG_DEBUG << "Create GroupThread (" << i + 1 << "/" << groupThreadInitNums << ")";
		GroupThread* tmp = new GroupThread(10);
		gThreads.push_back(tmp);
	}
	PLOG_DEBUG << "Electro ThreadManager Init finished.";
}



/*
* Group Threads
*/

ThreadManager::GroupThread::GroupThread(int size) {
	this->size = size;

	PLOG_DEBUG << "Group Thread initilizing..";


	PLOG_DEBUG << "Group Thread init finished.";
}

int ThreadManager::GroupThread::getSize() {
	return this->size;
}