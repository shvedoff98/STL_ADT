// class implementation for ADT remote contoller
#include <iostream>
using namespace std;

class Remote {

    private:
        int volume;
        int channel;

    public:
        Remote(int vl, int ch) : volume{vl}, channel{ch} {};
        void turn_on() const;
        void turn_off() const;

        int set_volume(int vl);
        int set_channel(int ch);
};

void Remote::turn_off() const
{
    cout << "Remote controller is shutdown.\n";
}

void Remote::turn_on() const
{
    cout << "Remote controller is turned on.\n";
}

int Remote::set_volume(int vl)
{
    cout << "Volume changed to: " << vl << "\n";
    return volume = vl;
}

int Remote::set_channel(int ch)
{
    cout << "Now channel: " << ch << "\n";
    return channel = ch;
}

int main(int argc, char* argv[])
{
    Remote my_remote(15,24);
    my_remote.turn_on();
    my_remote.turn_off();
    my_remote.turn_on();
    my_remote.set_volume(66);
    my_remote.set_channel(1223);
}
