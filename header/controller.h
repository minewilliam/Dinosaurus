class Controller
{
    private:
    char* PhonemeActif;
    public:
    Controller();
    ~Controller();
    void ReadPhoneme(char* unPhoneme);
    char getPhoneme();
    void resetPhoneme();
};