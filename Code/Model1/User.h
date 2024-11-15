/**
 * Project Untitled
 */


#ifndef _USER_H
#define _USER_H

class User {
public: 
    int id;
    string locationRequest;
    string name;
    string email;
    
string requestMap();
    
/**
 * @param feedback
 */
void sendFeedback(string feedback);
};

#endif //_USER_H