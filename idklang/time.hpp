#include <chrono>
#include <thread>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std::chrono;

uint64_t millis() {
  
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

void sleep(int x){
  std::this_thread::sleep_for(milliseconds(x));
}
