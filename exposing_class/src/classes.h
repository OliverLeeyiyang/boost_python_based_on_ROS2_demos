#include <string>

class RealWorld
{
    public:
        RealWorld(std::string n, char sex) : name(n), sex('m'), age(0.0){};
        std::string name;

        void Welcome();
        void SetAge(int age); 
        int GetAge();
        std::string GetName();
        char GetSex();

    private:
        char sex;
        int age;
};
