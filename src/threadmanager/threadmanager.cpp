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

int32_t loc = 0;
int32_t sub_loc = 0;



/*
* Add a human into the threads
*/

Human::human_id ThreadManager::ThreadManager::createHuman(std::string name) {
	if (sub_loc > gThreads[loc]->getSize() - 1) { ++loc; }
	if (loc > gThreads.size() - 1) {
		PLOG_DEBUG << "Current GroupThread full, allocating a new one [(loc, sub_loc, gThreads.size()) = (" << loc << ", " << sub_loc << ", " << gThreads.size() << ")]";
		// Allocate a new GroupThread if the latest one is full
		GroupThread* tmp = new GroupThread(10); 
		gThreads.push_back(tmp);
		loc = 0;
	}
	// Create new human
	Human::human_id id = { loc, sub_loc };
	Human::Human tmp_h(name, id);
	PLOG_DEBUG << "LOC = " << loc << " SUB_LOC = " << sub_loc;
	gThreads[loc]->addHuman(tmp_h);
	++sub_loc;                                                                                                                                                                                                                                                  
	// return id
	return id; // tmp
}

/*Human::Human* ThreadManager::ThreadManager::getHumanById(uint64_t id) {
	uint32_t loc = (uint32_t)((id & 0xFFFFFFFF00000000LL) >> 32), sub_loc = (uint32_t)(id & 0xFFFFFFFFLL);
	return NULL;
}*/

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

void ThreadManager::GroupThread::addHuman(Human::Human _human) {
	PLOG_DEBUG << "Adding human with name: " << _human.get_name();
	vec.push_back(_human);
}