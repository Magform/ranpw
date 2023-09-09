#ifndef Credits_H_
#define Credits_H_


class Credits {
    public:
        char* getName() {
            return authorName;
        }
        char* getAlias() {
            return authorAlias;
        }

    private:
        char* authorName = "Nicolas Ferraresso";
        char* authorAlias = "Magform";
};

#endif //Credits_H_
