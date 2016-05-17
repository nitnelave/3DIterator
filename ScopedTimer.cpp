#include "ScopedTimer.h"



ScopedTimer::ScopedTimer(double& result) :
    _begin(clock_t::now()),
    _result(result)
{}


ScopedTimer::~ScopedTimer()
{
    _result = (clock_t::now() - _begin).count();
}
