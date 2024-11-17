/**
 * Project Untitled
 */


#ifndef _USER_H
#define _USER_H
#include <string>
#include <vector>

using namespace std;

class User {
public: 
    int id;
    string locationRequest;
    
string requestMap();
    
/**
 * @param feedback
 */
void sendFeedback(string feedback);
};

#endif //_USER_H