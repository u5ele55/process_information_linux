#include "DirectoryChecker.h"

#include <sys/types.h>
#include <sys/stat.h>


DirectoryState DirectoryChecker::checkDirectory(const std::string &path)
{
    struct stat info;

    if ( stat(path.c_str(), &info) != 0 ) {
        return DirectoryState::NO_ACCESS;
    }
    else if( info.st_mode & S_IFDIR ) {
        return DirectoryState::OK;
    } 
    else {
        return DirectoryState::DOESNT_EXIST;
    }
}