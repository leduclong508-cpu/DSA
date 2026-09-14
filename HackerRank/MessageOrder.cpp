/*
    Le Duc Long 
    Topic: Message Order
    12/09/2026: first edition
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Message {
public: 
    Message() {}
    
    // Constructor to initialize the message with text and an ID
    Message(const string& text, int id) : text_(text), id_(id){}
    
    const string& get_text() {
        return text_;
    }
    
    // Overload the less-than operator to compare messages based on their ID
    bool operator<(const Message& other) const {
        return id_ < other.id_;
    }
    
private:
    string text_;
    int id_; //Store the order of the message
};

class MessageFactory {
public:
    MessageFactory() : current_id_(0) {} // Initialize the current ID to 0

    Message create_message(const string& text) {
        // Create a new message with the given text and the current ID
        Message msg(text, current_id_);
        current_id_++;
        return msg;
    }
    
private:
    int current_id_; // Keep track of the order of messages
};

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
    // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());         
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
