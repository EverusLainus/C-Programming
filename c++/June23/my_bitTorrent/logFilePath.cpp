#include <iostream>
#include <loguru.hpp>


void performSimpleTask(bool enableLogging, const std::string& logFilePath) {
    // Initiates the logger if logging is enabled
    if (enableLogging) {
        loguru::g_stderr_verbosity = loguru::Verbosity_OFF;
        loguru::g_flush_interval_ms = 100;
        loguru::add_file(logFilePath.c_str(), loguru::Truncate, loguru::Verbosity_MAX);

        LOG_F(INFO, "Logging is enabled. Log file path: %s", logFilePath.c_str());
    } else {
        loguru::g_stderr_verbosity = loguru::Verbosity_OFF;
    }

    // Your simple task logic goes here
    int sum = 0;
    for (int i = 1; i <= 5; ++i) {
        // Your actual task implementation goes here
        sum += i;

        // Log some information if logging is enabled
        if (enableLogging) {
            LOG_F(INFO, "Adding %d to the sum. Current sum: %d", i, sum);
        }
    }

    LOG_F(INFO, "Task completed. Final sum: %d", sum);
}

int main() {
    // Example usage
    std::string logFilePath = "example.log";
    
    // Enable logging
    performSimpleTask(true, logFilePath);

    // Disable logging
    performSimpleTask(false, logFilePath);
    std::string torrentFilePath = "./example.log";

    /*
    same as:
    std::cout << "Parsing Torrent file " << torrentFilePath << "..." << std::endl;
    */

    std::cout << "Parsing Torrent file " + torrentFilePath + "..." << std::endl;

    return 0;
}

