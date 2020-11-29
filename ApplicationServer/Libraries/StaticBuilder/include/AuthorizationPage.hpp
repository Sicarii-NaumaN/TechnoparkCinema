#pragma once

#include <string>
#include <map>
#include "StaticBuilder.hpp"

typedef std::map<std::string, std::string> UserMatadata;

class AuthorizationPage: public StaticBuilder {
 protected:
    UserMatadata userMetadata;
    bool AuthSuccess;
    void AddErrorCode();
    //  Will add more as page's functionality grows.

 public:
    AuthorizationPage(FCGIClient dbClient, FCGIClient videoFilesClient);

    virtual void ParseRequestData(FastCGIData requestData);
    virtual void AddMetadata();
    virtual void CreateResponseData();
    virtual FastCGIData GetResponseData();
}
