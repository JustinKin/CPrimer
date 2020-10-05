#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
#include <functional>
#include <iterator>
#include <map>
#include <set>
#include <utility>
#include <memory>

#include "MAIL.H"

using namespace std;

void Message::save(Folder& folder_)
{
    mbox.insert(&folder_);
    folder_.addMsg(this);
}

void Message::remove(Folder& folder_)
{
    mbox.erase(&folder_);
    folder_.remMsg(this);
}

void Message::add2Folder(const Message& message_)
{
    for(auto const& c : message_.mbox)
        c->addMsg(this);
}

Message::Message(const Message& message_):contents(message_.contents),mbox(message_.mbox)
{
    add2Folder(message_);
}

void Message::rem_from_Folders()
{
    for(auto const& c : mbox)
    c->remMsg(this);

}

Message::~Message()
{
    rem_from_Folders();
}

Message& Message::operator=(const Message& message_)//461,t2
{
    rem_from_Folders();
    contents = message_.contents;
    mbox = message_.mbox;
    add2Folder(message_);

    return *this;
}

void Message::move_Fold(Message* message_)
{
    mbox = std::move(message_->mbox);
    for(auto c : mbox)
    {
        c->remMsg(message_);
        c->addMsg(this);
    }
    message_->mbox.clear();
}

Message::Message(Message&& message_):contents(std::move(message_.contents))
{
    move_Fold(&message_);
}

Message& Message::operator=(Message&& message_)
{
    if(this != &message_)
    {
        rem_from_Folders();
        contents = std::move(message_.contents);
        move_Fold(&message_);
    }
    return *this;
}

void swap(Message& msg1, Message& msg2)
{
    using std::swap;
    for(auto c :msg1.mbox)
        c->remMsg(&msg1);
    for(auto c :msg2.mbox)
        c->remMsg(&msg2);
    swap(msg1.mbox, msg2.mbox);
    swap(msg1.contents, msg2.contents);
    for(auto c :msg1.mbox)
        c->addMsg(&msg1);
    for(auto c :msg2.mbox)
        c->addMsg(&msg2);
}

void Folder::addMsg(Message* message_)
{
    msg.insert(message_);
}

void Folder::remMsg(Message* message_)
{
    msg.erase(message_);
}

