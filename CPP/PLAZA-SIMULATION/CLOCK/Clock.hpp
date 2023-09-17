#include <chrono>
#include <iostream>
class Chrono
{
    public:
    Chrono(){_startTime = std::chrono::steady_clock::now();}
    ~Chrono(){}
    void start(){
        _curentTime = std::chrono::steady_clock::now();
        _elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(_curentTime - _startTime).count();
    }
    void end(){}
    float getStartTime(){return std::chrono::duration<float>(_startTime.time_since_epoch()).count();}
    float getElapsedTime(){ return _elapsedTime;}
    float getCurrentTime(){return std::chrono::duration<float>(_curentTime.time_since_epoch()).count();}

    std::chrono::time_point<std::chrono::steady_clock> _startTime;
    std::chrono::time_point<std::chrono::steady_clock> _curentTime;
    float _elapsedTime;

};