#ifndef WHEEL_H
#define WHEEL_H

class Wheel {
    public:
        Wheel();

        int getMinVal();
        void setMinVal(int value);
        int getMaxVal();
        void setMaxVal(int value);

        virtual int spin();

    protected:
        int minVal;
        int maxVal;
};

#endif
