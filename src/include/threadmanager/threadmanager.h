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
#ifndef THREADMAN_H
#define THREADMAN_H

#include <vector>

namespace ThreadManager {

	/*
	* A Groupthread is responsible for [size]
	* amount of humans
	*/
	class GroupThread {
	private:
		int size;
	public:
		GroupThread(int size);

		// Getters
		int getSize();

		// Funcs

	};

	/*
	* Manages all GroupThreads and Threads
	*/
	class ThreadManager {
	private:
		int groupThreadInitNums;

		// Group Threads
		std::vector<GroupThread*> gThreads;
	public:
		ThreadManager(int groupThreadInitNums);
	};

	
}
#endif