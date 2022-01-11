//
//  main.cpp
//  AdventOfCode201223_1
//
//  Created by Kjell-Olov Högdal on 2020-12-23.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <list>

char const* pExample1 = R"(32415)";
char const* pExample2 = R"(389125467)";
char const* pPuzzleInput = R"(463528179)";

class Part1CrabCups {
public:
    std::string sCups {};
    Part1CrabCups& operator+=(int const MOVES) {
        for (int i = 0; i<MOVES; ++i) {
            std::cout << "\nCups : " << sCups;
            /*
            1) The crab picks up the three cups that are immediately clockwise of the current cup. They are removed from the circle; cup spacing is adjusted as necessary to maintain the circle.
            */
            std::string sPicked = sCups.substr(1,3);
            sCups.erase(1,3);
            std::cout << "\npicked : " << sPicked;
            std::cout << "\nRemaining cups : " << sCups;
            /*
            2) The crab selects a destination cup: the cup with a label equal to the current cup's label minus one. If this would select one of the cups that was just picked up, the crab will keep subtracting one until it finds a cup that wasn't just picked up. If at any point in this process the value goes below the lowest value on any cup's label, it wraps around to the highest value on any cup's label instead.
            */
            std::string::size_type pos {std::string::npos};
            char next = sCups[0];
            do {
                next -= 1;
                if (next <= '0') next = '9';
                pos =  sCups.find(next);
            } while (pos == std::string::npos);
            std::cout << "\nSelected : " << sCups.substr(pos,1);
            /*
            3) The crab places the cups it just picked up so that they are immediately clockwise of the destination cup. They keep the same order as when they were picked up.
            */
            sCups.insert(pos+1, sPicked);
            std::cout << "\npicked reinserted : " << sCups;
            /*
            4) The crab selects a new current cup: the cup which is immediately clockwise of the current cup.
            */
            std::rotate(sCups.begin(), sCups.begin()+1,sCups.end());
            std::cout << "\nCups for next round : " << sCups;
        }
        return *this;
    }
    std::string cups_after_1() {
        std::string result{sCups};
        while (result[0] != '1') {
            std::rotate(result.begin(), result.begin()+1, result.end());
        }
        return result;
    }
private:
};

template<int N>
class Part2CrabCups {
public:
    using Id = int;
    using Cups = std::list<Id>;
    const Id MAX{N};
    Part2CrabCups(std::string const& init_cups) {
        for (char ch : init_cups) this->cups.push_back(static_cast<Id>(ch-'0'));
    }
    void print(std::string const& caption,Cups const& cups) const {
        std::cout << caption;
        for (Id const& id : cups) std::cout << " " << id << std::flush;
    }
    void print() const {
        this->print("\nCups ",cups);   
    }
    Part2CrabCups& operator+=(int const MOVES) {
        int progress_count{0};
        Id event_horizon{MAX};
        for (int i = 0; i<MOVES; ++i) {
            if (progress_count++%10000==0) std::cout << "\n" << cups.size() << " " << MOVES-i;
            print();
            /*
            1) The crab picks up the three cups that are immediately clockwise of the current cup. They are removed from the circle; cup spacing is adjusted as necessary to maintain the circle.
            */
            std::pair<Cups::iterator,Cups::iterator> picked_range{cups.begin(),cups.begin()};
            std::advance(picked_range.first,1);
            std::advance(picked_range.second,4);
            
            Cups picked{picked_range.first,picked_range.second};
            cups.erase(picked_range.first,picked_range.second);
            print("\nPicked ",picked);
            print("\nRemaining ",cups);
            /*
            2) The crab selects a destination cup: the cup with a label equal to the current cup's label minus one. If this would select one of the cups that was just picked up, the crab will keep subtracting one until it finds a cup that wasn't just picked up. If at any point in this process the value goes below the lowest value on any cup's label, it wraps around to the highest value on any cup's label instead.
            */
            auto next = (cups.front()>1)?cups.front()-1:MAX;
            while (std::find(picked.begin(),picked.end(),next)!=picked.end()) {
                --next;
                if (next <= 0) 
                    next = MAX;
            }
            // Expand cups with next if it is not yet in there
            auto selected=cups.end();
            if (next>9 and next==event_horizon) {
                cups.push_back(next);
                --event_horizon;
                selected = cups.end();--selected;
            }
            else selected = std::find(cups.begin(),cups.end(),next);

            std::cout << "\nSelected : " << *selected << std::flush;
            /*
            3) The crab places the cups it just picked up so that they are immediately clockwise of the destination cup. They keep the same order as when they were picked up.
            */
            cups.insert(++selected,picked.begin(),picked.end());
            print("\npicked reinserted ",cups);
            /*
            4) The crab selects a new current cup: the cup which is immediately clockwise of the current cup.
            */
            auto begin_plus_one = cups.begin();++begin_plus_one;
            std::rotate(cups.begin(), begin_plus_one,cups.end());
        }
        return *this;
    }
    Cups cups_from_1() {
        Cups result{cups};
        while (result.front() != 1) {
            auto begin_plus_one = result.begin();std::advance(begin_plus_one,1);
            std::rotate(result.begin(), begin_plus_one, result.end());
        }
        return result;
    }
private:
    Cups cups{};
};


int main(int argc, const char * argv[]) {
    // Part2CrabCups<9> crabs{pExample2}; // Part 1 example
    // crabs+=10;
    Part2CrabCups<9> crabs{pPuzzleInput}; // Part 1
    crabs+=100;
    // Part2CrabCups<100> crabs{pPuzzleInput}; // Investigate
    // Part2CrabCups<1000000> crabs{pExample2}; // Test part 2
    // crabs += 10000000;
    auto cups = crabs.cups_from_1();
    crabs.print();
    auto second = cups.begin();std::advance(second,1);
    auto third = cups.begin();std::advance(third,2);
    std::cout << "\nAnswer is : " << *second << " " << *third;
    std::cout << "\n\n";
    return 0;
}
