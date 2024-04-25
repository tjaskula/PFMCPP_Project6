/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference and don't change the return type either.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>

struct T
{
    int value;
    std::string name;
    T(int v, const char* uname) //1
    {
        value = v; //2
        name = uname; //3
    }
};

struct ValueComparator                                //4
{
    T* compare(T& a, T& b) //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;

        return nullptr;
    }
};

struct U
{
    float value1 { 200.0f }, value2 { 714.0f };
    float update(const float& updatedValue)      //12
    {
        std::cout << "U's value1 value: " << value1 << std::endl;
        value1 = updatedValue;
        std::cout << "U's value1 updated value: " << value1 << std::endl;
        while( std::abs(value2 - value1) > 0.001f )
        {
            if (value2 > value1)
            {
                value2 -= (value2 - value1) / 2.0f;  // Move halfway closer to value1
            }
            else
            {
                value2 += (value1 - value2) / 2.0f;  // Move halfway closer to value1
            }
        }
        std::cout << "U's value2 updated value: " << value2 << std::endl;
        return value2 * value1;
    }
};

struct ValueUpdater
{
    static float update(U& that, const float& updatedValue)        //10
    {
        std::cout << "U's value1 value: " << that.value1 << std::endl;
        that.value1 = updatedValue;
        std::cout << "U's value1 updated value: " << that.value1 << std::endl;
        while( std::abs(that.value2 - that.value1) > 0.001f )
        {
            if (that.value2 > that.value1)
            {
                that.value2 -= (that.value2 - that.value1) / 2.0f;  // Move halfway closer to value1
            }
            else
            {
                that.value2 += (that.value1 - that.value2) / 2.0f;  // Move halfway closer to value1
            }
        }
        std::cout << "U's value2 updated value: " << that.value2 << std::endl;
        return that.value2 * that.value1; 
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T ten(10 , "ten");                                             //6
    T eleven(11, "eleven");                                             //6
    
    ValueComparator f;                                            //7
    auto* smaller = f.compare(ten, eleven);                             //8
    if (smaller == nullptr)
    {
        std::cout << "the compre function returned nullptr because both arguments have the same value." << std::endl;
    }
    else
    {
        std::cout << "the smaller one is " << smaller->name << std::endl; //9
    }
    
    U updatable1;
    const float updatedValue = 5.f;
    std::cout << "[static func] updatable1's multiplied values: " << ValueUpdater::update(updatable1, updatedValue) << std::endl;                  //11
    
    U updatable2;
    std::cout << "[member func] updatable2's multiplied values: " << updatable2.update( updatedValue ) << std::endl;
}
