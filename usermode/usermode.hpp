#pragma once

#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <iostream>
#include <cstdint>
#include <chrono>
#include <fstream>
#include <set>
#include <regex>
#include <thread>
#include <winternl.h>

// ext/includes
#include "json.hpp"
#include "easywsclient.hpp"
#include "fnv1a.hpp"

using namespace ext;
using namespace std;

// src/defines 是否使用本地IP 局域网设置为0
#define USE_LOCALHOST 0

// src/macros
#define LOG(str, ...) \
	{ \
        const auto filename = filesystem::path(__FILE__).filename().string(); \
        printf("[%s] " str "\n", filename.c_str(), __VA_ARGS__); \
    }

#define LOG_ERROR(str, ...) \
    { \
        const auto filename = filesystem::path(__FILE__).filename().string(); \
        printf("[%s:%d] " str "\n", filename.c_str(), __LINE__, __VA_ARGS__); \
    }


#include "utils.hpp"
#include "features.hpp"