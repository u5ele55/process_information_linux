#include "GetterMaster.h"

#include <map>
#include <functional>
#include <stdexcept>

#include "InfoGetters/PPIDGetter.h"
#include "InfoGetters/NameGetter.h"
#include "InfoGetters/StateGetter.h"
#include "InfoGetters/UIDGetter.h"
#include "InfoGetters/ThreadsGetter.h"
#include "InfoGetters/ThreadsPIDGetter.h"

GetterMaster::GetterMaster(const std::string &pid) : pid(pid) {}

AbstractInfoGetter *GetterMaster::operator()(const std::string &getterName)
{
    std::map<std::string, std::function<AbstractInfoGetter*()>> base = {
        {"ppid", [&](){ return new PPIDGetter(pid); }},
        {"name", [&](){ return new NameGetter(pid); }},
        {"state", [&](){ return new StateGetter(pid); }},
        {"uid", [&](){ return new UIDGetter(pid); }},
        {"threads", [&](){ return new ThreadsGetter(pid); }},
        {"thpid", [&](){ return new ThreadsPIDGetter(pid); }},
    };

    if (base.count(getterName) == 0) {
        throw std::invalid_argument("Unknown keyword!");
    }

    return base[getterName]();
}