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
#include <pch.h>
#include <plog/Log.h>
#include <plog/Initializers/RollingFileInitializer.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Initializers/ConsoleInitializer.h>

/*
* Thread Manager
*/


ThreadManager::ThreadManager::ThreadManager() {
	PLOG_DEBUG << "Electro ThreadManager Startup";
	PLOG_DEBUG << "Creating Startup GroupThread";

	// init group threads. Uses a vector to store all of them.
	// init allocation size is defined by the program.

		GroupThread* tmp = new GroupThread(10);
		gThreads.push_back(tmp);

	PLOG_DEBUG << "Electro ThreadManager Init finished.";
}

int loc = 0;
int sub_loc = 0;

void ThreadManager::ThreadManager::createHuman(std::string name) {
	if (sub_loc > gThreads[loc]->getSize() - 1) { ++loc; }
	if (loc > gThreads.size() - 1) {
		GroupThread* tmp = new GroupThread(10);
		gThreads.push_back(tmp);
	}

	Human::Human tmp_h(name);
	gThreads[loc]->addHuman(tmp_h);
	++sub_loc;
}


/*
* Group Threads
*/

ThreadManager::GroupThread::GroupThread(int size) {
	PLOG_DEBUG << "Group Thread initilizing..";
	this->size = size;
	PLOG_DEBUG << "Group Thread init finished.";
}

int ThreadManager::GroupThread::getSize() {
	return this->size;
}

void ThreadManager::GroupThread::addHuman(Human::Human _human) {
	PLOG_DEBUG << "Adding human with name: " << _human.get_name();
	vec.push_back(_human);
}