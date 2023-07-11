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
#include <enviorment/enviorment.h>
#include <pch.h>
#include <plog/Log.h>
#include <plog/Initializers/RollingFileInitializer.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Initializers/ConsoleInitializer.h>

#define STATUS_OK "OK"
#define STATUS_ISSUES "NON-FATAL ISSUES"
#define STATUS_FAILED "FAILED"
#define STATUS_BAD "CHINMAY"

/*
* Constructer (lamo)
*/

Enviorment::Enviorment::Enviorment() {
	PLOG_DEBUG << "Enviorment Intilizing..";
	// 
	std::string status = STATUS_BAD;
	PLOG_DEBUG << "Enviorment Intilizing finished - [" << status << "]";
}

template<typename... Args>
// Note for User: Please only pass ints please dear god I will force you to make your own vecotr
//
Enviorment::Source::Source(Transform::Point value, Args... args) {
	std::vector<Transform::Point> values{ value, args... };
	vertices = values;

	for (const auto& i : regions) {
		if (Transform::checkOverlap(i, vertices)) {
			regions.push_back(vertices);
		}
	}
}