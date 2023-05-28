/*
Imagine there are some people in the room. 
One (and only one) of them can be a celebrity.
Sightns of the celebrity: they knows nobody in the room,
but every person in the room knows them. 

You are given a map with connections between people in this room. 
For example, {1 : 3, 4, 5} means that person 1 knows persons 3, 4, 5.

Please find the celebrity by minimal number of steps 
or proove that there is no celebrity in the room. 
*/

#include <iostream>
#include <map>
#include <vector> 
#include <algorithm>

int findCelebrity(std::map<int, std::vector<int>>& connections)
{
    int celebrityIndex = -1;

    for (const auto& [key, value] : connections) 
    {
        // only one person can be a celebrity
        // celebrity doesn't know anyone in the room
        if(value.empty()) 
        {
            celebrityIndex = key;
            break;
        }
    }

    // how many people know celebrity
    int knownNumber = 0;

    if(celebrityIndex != -1)
    {
        for (const auto& [key, value] : connections)
        {
            if(key != celebrityIndex)
            {
                // if someone doesn't know potential celebrity, they aren't a celebrity
                if(std::find(value.begin(), value.end(), celebrityIndex) == value.end()) break;
                else knownNumber++;
            }
        }
    }

    if(knownNumber == connections.size() - 1 ) return celebrityIndex;

    // if there is no celebrities in the room, return -1
    return -1;
}

int main()
{
    std::map<int, std::vector<int>> connections;
    connections[0] = {1, 2, 3};
    connections[1] = {2, 4};
    // potential celebrity - person 2
    connections[2] = {};
    connections[3] = {2, 6, 1};
    connections[4] = {2, 5};
    connections[5] = {2, 3, 4, 6};
    connections[6] = {1, 2, 3};

    auto c = findCelebrity(connections);
    if(c == -1) std::cout << "There are no celebrities in the room";
    else std::cout << "Person #" << c << " is a celebrity";
}