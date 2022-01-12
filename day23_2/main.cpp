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
#include <ranges>
#include <sstream>
#include <map>

char const* pExample1 = R"(32415)";
char const* pExample2 = R"(389125467)";
char const* pPuzzleInput = R"(463528179)";

class Part1CrabCups {
public:
    std::string sCups {};
    Part1CrabCups& operator+=(int const MOVES) {
        const int PROGRESS_STEP{100000};
        int progress_count{PROGRESS_STEP};
        std::cout << "\n";
        for (int i = 0; i<MOVES; ++i) {
            if (progress_count++%PROGRESS_STEP==0) std::cout << '.' << std::flush;
            // std::cout << "\nCups : " << sCups;
            /*
            1) The crab picks up the three cups that are immediately clockwise of the current cup. They are removed from the circle; cup spacing is adjusted as necessary to maintain the circle.
            */
            std::string sPicked = sCups.substr(1,3);
            sCups.erase(1,3);
            // std::cout << "\npicked : " << sPicked;
            // std::cout << "\nRemaining cups : " << sCups;
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
            // std::cout << "\nSelected : " << sCups.substr(pos,1);
            /*
            3) The crab places the cups it just picked up so that they are immediately clockwise of the destination cup. They keep the same order as when they were picked up.
            */
            sCups.insert(pos+1, sPicked);
            // std::cout << "\npicked reinserted : " << sCups;
            /*
            4) The crab selects a new current cup: the cup which is immediately clockwise of the current cup.
            */
            std::rotate(sCups.begin(), sCups.begin()+1,sCups.end());
            // std::cout << "\nCups for next round : " << sCups;
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
        auto digit_to_int = [](char digit){return digit-'0';};
        std::ranges::transform(init_cups,std::back_inserter(cups),digit_to_int);
        // fill up the range 10...1000000 (part 2, no effect for part 1 cups count)
        std::ranges::copy(std::ranges::iota_view{cups.size()+1,static_cast<size_t>(MAX+1)},std::back_inserter(cups));
        for (auto iter=cups.begin();iter!=cups.end();++iter) this->location[*iter] = iter;
    }
    void print(std::string const& caption,Cups const& cups) const {
        std::cout << caption;
        auto take_front = std::min(cups.size(),static_cast<size_t>(15));
        auto take_back = std::min(std::max(size_t{0},cups.size()-take_front),static_cast<size_t>(15));
        std::ranges::copy(cups | std::views::take(take_front) ,std::ostream_iterator<int>(std::cout, " "));        
        if (take_back>0) std::cout << "...";
        std::ranges::copy(cups | std::views::reverse | std::views::take(take_back) | std::views::reverse ,std::ostream_iterator<int>(std::cout, " "));
    }
    void print() const {
        this->print("\nCups ",cups);   
    }
    template <typename It>
    Cups::iterator advanced(It iter,int count) {
        std::advance(iter,count);
        return iter;
    }
    Cups::iterator locate(Id id) {
        return location[id];
    }
    void pick_cups() {
        /*
        1) The crab picks up the three cups that are immediately clockwise of the current cup. They are removed from the circle; cup spacing is adjusted as necessary to maintain the circle.
        */
        // splice: unlink from cups the range begin+1..begin+4, and link them into picked before picked.end()
        picked.splice(picked.end(),cups,advanced(cups.begin(),1),advanced(cups.begin(),4));
        // print("\nPicked ",picked);
        // print("\nRemaining ",cups);       
    }
    void select_next() {
        /*
        2) The crab selects a destination cup: the cup with a label equal to the current cup's label minus one. If this would select one of the cups that was just picked up, the crab will keep subtracting one until it finds a cup that wasn't just picked up. If at any point in this process the value goes below the lowest value on any cup's label, it wraps around to the highest value on any cup's label instead.
        */
        auto next = (cups.front()>1)?cups.front()-1:MAX;
        while (std::find(picked.begin(),picked.end(),next)!=picked.end()) {
            --next;
            if (next <= 0) 
                next = MAX;
        }
        this->selected = this->locate(next);
        // std::cout << "\nSelected : " << *selected << std::flush;
    }
    void place_picked() {
        /*
        3) The crab places the cups it just picked up so that they are immediately clockwise of the destination cup. They keep the same order as when they were picked up.
        */
        cups.splice(advanced(selected,1),picked,picked.begin(),picked.end());
        // print("\npicked reinserted ",cups);
    }
    void make_next_current() {
        /*
        4) The crab selects a new current cup: the cup which is immediately clockwise of the current cup.
        */
        // splice from cups.begin() to cups.end()
        // splice unlinks elements from source list and links them into target list
        // This works also when source and target is the same list. 
        // 1. unlinks cups.begin() from cups
        // 2. links unlinked element before cups.end()
        // = Ineffect the list is rotated left without violating any interator (e.g., insertion_point) having the value cups.begin()
        cups.splice(cups.end(),cups,cups.begin());
    }
    Part2CrabCups& operator+=(int const MOVES) {
        const int PROGRESS_STEP{100000};
        int progress_count{PROGRESS_STEP};
        std::cout << "\n";
        for (int i = 0; i<MOVES; ++i) {
            if (progress_count++%PROGRESS_STEP==0) std::cout << '.' << std::flush;
            this->pick_cups();
            this->select_next();
            this->place_picked();
            this->make_next_current();
        }
        return *this;
    }
    std::pair<Id,Id> second_and_third() {
        auto first = locate(1);
        return {*advanced(first,1),*advanced(first,2)};
    }
private:
    // Game state
    Cups cups{};
    Cups picked{};
    Cups::iterator selected{};
    std::map<Id,Cups::iterator> location{};
};

using Result = size_t;

int main(int argc, const char * argv[]) {
    Part1CrabCups crabs1{pExample2};
    crabs1 += 100;
    std::cout << "\nPart 1: " << crabs1.cups_after_1();
    // Part2CrabCups<9> crabs{pExample2}; // Part 1 example
    // crabs+=10;
    // Part2CrabCups<9> crabs{pPuzzleInput}; // Part 1
    // crabs+=100;
    // Part2CrabCups<100> crabs{pPuzzleInput}; // Investigate
    // Part2CrabCups<1000000> crabs2{pExample2}; // Test part 2
    // crabs2 += 10000000;
    Part2CrabCups<1000000> crabs2{pPuzzleInput}; // part 2
    crabs2 += 10000000;
    auto [second,third] = crabs2.second_and_third();
    Result result = static_cast<Result>(second) * static_cast<Result>(third);
    std::cout << "\nPart 2: " << second << " * " << third << " = " << result;
    std::cout << "\n\n";
    return 0;
}