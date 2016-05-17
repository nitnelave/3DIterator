#pragma once

#include <chrono>


class ScopedTimer
{
public:
    /**
      Construct a ScopedTimer, with the double in which it will store the result, in microseconds.
      The timer is started on construction, and stopped on destruction.
    */
    ScopedTimer(double& result);

    /**
      Stop the timer, storing the interval in result.
    */
    ~ScopedTimer();

private:
    using clock_t = std::chrono::steady_clock;
    using time_t = clock_t::time_point;
    using usec_t = std::chrono::duration<double, std::micro>;
    time_t _begin;
    double& _result;
};

