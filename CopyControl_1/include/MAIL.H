#ifndef __MAIL_H__
#define __MAIL_H__

#include <iostream>
#include <memory>
using std::shared_ptr;
// #include <vector>
/* using std::vector;
using std::string;
using std::make_shared;
using std::weak_ptr;
using std::initializer_list;
using std::runtime_error;
using std::out_of_range;
 */

class Folder;


class Message
{
friend class Folder;
friend void swap(Message& msg1, Message& msg2);
public:
    explicit Message(const std::string& str = "") : contents(str) { };
    Message(const Message& message_);//460,b5
    Message& operator=(const Message& message_);//461,t2
    ~Message();
    Message(Message&& message_);
    Message& operator=(Message&& message_);

    void save(Folder& folder_);
    void remove(Folder& folder_);//delete msg in all folders
private:
    std::string contents;
    std::set<Folder*> mbox;
    void add2Folder(const Message& message_);
    void rem_from_Folders();
    void move_Fold(Message* message_);
};

class Folder
{
friend class Message;
public:
    Folder();
    Folder(const Folder& folder_);
    ~Folder();
    void addMsg(Message* message_);
    void remMsg(Message* message_);
private:
    std::set<Message*> msg;
};

#endif