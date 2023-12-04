/*
 * Example of Humans reacting to enviorment
 */

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
	Human::human_id val = Chase::addHuman("Person1");

    // create enviorment
}