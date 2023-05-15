#ifndef UTILS_HPP
#define UTILS_HPP

#include "../Headers.hpp"
#include <condition_variable>
extern std::mutex              mtx;
extern std::condition_variable cv;
extern bool                    threadSignal;

#endif
