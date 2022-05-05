#pragma once

#include <string>
#include <mutex>
#include <atomic>

class Singleton
{
public:
    static Singleton& GetInstance();
private:
    Singleton(const std::string& name) {}
    ~Singleton() {}
    Singleton() = delete;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;   
    
    std::string m_name;
    static std::mutex m_mutex;
    static std::atomic<Singleton*> m_instance;
};



