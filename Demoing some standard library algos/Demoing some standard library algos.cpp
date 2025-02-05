#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::vector, std::string; 

bool stringLengthIsGreaterThan3(const string& theString)
{
    return (theString.length() > 3);
}


int main()
{
    vector<string> names =
    {
        "Alice",
        "Bob",
        "Carol",
        "Darth", 
        "asdfasdfasdfasdf", 
        "123"
    };

    //suppose I want to print the number of names with length > 3:
    cout << "Number of names with len > 3: " 
        << std::count_if(names.begin(), names.end(), stringLengthIsGreaterThan3) << "\n";
    
    std::set_intersection();

    std::merge();

    

    return 0;
}