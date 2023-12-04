// CHASEdll-testing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <chase.h>
#include <plog/Log.h>
#include <plog/Initializers/RollingFileInitializer.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Initializers/ConsoleInitializer.h>

#include <bit>
#include <array>
#include <cstdint>
#include <iostream>


int main() {
	Chase::init();
	// create test human
	plog::init<plog::TxtFormatter>(plog::debug, plog::streamStdOut);
	Human::human_id val = Chase::addHuman("Bro");
	for (int i = 0; i < 5; i++) {
		std::string name = "Dummy" + std::to_string(i);
		val = Chase::addHuman(name);
		PLOG_INFO << "[TEST PROGRAM] Created human " << i;
	}
	PLOG_INFO << "[TEST PROGRAM] LOC = " << val.loc << " SUB_LOC = " << val.sub_loc;
	
	PLOG_INFO << "[TEST PROGRAM] Retrived human name: " << Chase::_debugGetName(val);

	Enviorment::Source source(Transform::Point(0,0,0), Transform::Point(0,0,5));
	Chase::env->addSource(source);
}
