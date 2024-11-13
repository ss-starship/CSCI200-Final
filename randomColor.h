#ifndef RANDOMCOLOR_H
#define RANDOMCOLOR_H

#include "CustColor.h"


class RandomColor final : public CustColor {
    public:
        /**
         * @brief Construct a new Random Color object, sets private vectors to {}
         * 
         */
        RandomColor();

        /**
         * @brief generates 3 ints and stores them in protected variables in custColor class
         * 
         */
        void makeRandomColor();

        /**
         * @brief override writeColor function to output random color values
         * 
         * @param out - where writing to
         * @param correct - picks what version is written
         */
        void writeColor(std::ofstream& out, bool correct) const;

        /**
         * @brief write outs special statistics and end
         * 
         * @param out - file to write to
         */
        void writeStats(std::ofstream& out) const;

    private:
        std::vector<int> _redVec; // stores all random red values for data
        std::vector<int> _greenVec; // stores all random green values for data
        std::vector<int> _blueVec; // stores all random blue values for data

        /**
         * @brief uses private vectors to average all random color values
         * experineced in a playthrough
         * 
         * @param out - file to write out to
         */
        void averageColor(std::ofstream& out) const;

        /**
         * @brief uses private vectors to find the minimum random color
         * values experienced in a playthrough
         * 
         * @param out - file to write out to
         */
        void min(std::ofstream& out) const;

        /**
         * @brief uses private vectors to find the maximum random color
         * values experienced in a playthrough
         * 
         * @param out - file to write out to
         */
        void max(std::ofstream& out) const;

        
};

#endif