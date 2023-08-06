

class Singleton
{
public:
    Singleton()
    {
        if(instance == nullptr)
        {
            instance = new Singleton();
        }
    };

    Singleton &getInstance()
    {   
        Singleton();
        return *instance;
    };

    Singleton(const Singleton&) = delete;
    Singleton &operator =(const Singleton&) = delete;

private:
    static Singleton *instance;
};

Singleton * Singleton::instance = nullptr;