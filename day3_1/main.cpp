//
//  main.cpp
//  CodeOfAdvent201203_1
//
//  Created by Kjell-Olov Högdal on 2020-12-03.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>

const char* pData = R"(.#.#....###..#.#..............#
#......#####..##.##.#.......#.#
.###.....#..#.#..#..#.#......#.
.........##.#.....#.#..........
........##....#.......#.#..#..#
#.#..####...#.....#.#.#...#....
#....#...#.........#.....#..#.#
.#..........#..#.............#.
...##..##..#...####.#.#.#.#....
.#...####............##....#...
..##.....#.#......#......#.#.#.
..##......#..##.....#.#.....#.#
..#...#....#.#.........##......
#..##..##..#..##....#....##.#.#
..###.#....#.#.#...#......#.#.#
....#...#...#.........#.....##.
.#..#.#..........#.##.....#.#..
.#...#...###..#..#..####.#...#.
##..............#..#.#...###..#
.#..#.#.#...#..#...#..#........
..#.#......#.#..##...#.#..#....
...#.#.....#.##..#...#..#......
...#...##....##..#....#..#...#.
#......##.#.......#...#..#.#...
.#..#......####...#............
...#..##.#...#....#.#.#.#......
....##...........##.#.#...##...
#.##.###........#..###.#..##...
....#......#....##...##.#......
#.............#...#.........#..
..##.......#.......#.#...#...#.
...#....####...#...#....#.###..
...##......#...###.#...#....#..
...#.............#...#.......#.
...#..#.##.##.#..#.##.#..#....#
..####.....#..#............#...
##....##..#.#.#.#..#..#.....#..
......##...##......#.#.........
#.#............#.#.#..#......#.
...#.#.#.....#..#..#.#..##.....
.#.#.............###..#....##..
....#.###..#..#.....#..#.##....
..#.#....#.......#.......##..#.
.#.##.#.#..#..##.........##....
...#...###.##....#####.......#.
......#.....##...##...#....#.#.
###.......##..#.....#......#.#.
...#..#..#....#.#.....##..#...#
..#....##.......#....#.........
#....##.........##......#.#..#.
#.....#.#.#..##..#.#.....##....
......#....#...#...#.###....##.
#...####...###.##..#.#.#..##...
......###....###..##......#..##
.#.####.###..#.....#...#..#...#
.###.#.....#..#.#..#.....##..##
...##...#.####....#......###...
...##.......#.#..#......#.#....
......##....#......#.........#.
............#....#............#
..#.#..........#......#..#.....
.#...#.#.#......#..##..#....##.
..##.#.#.#..#...###..#.#.##.#..
..#......#.........#.......#...
...#...##.#.##......#.....#....
..#.....#..##....#..##..#.#.##.
....##....#.#...#..##.##.##....
..#.............#...#......#...
.#.#.#.##..#.#..##...#.........
.##...........#..#.#........#..
.#..##.....#....#...#...#......
#.#.....##.#..#...######....#..
....#..#...##...#.........###..
..##.#...##..#......#.##..#...#
##..##...........#.......#.#...
.......##..##...###.##.......#.
.#.##...#.##...............#...
.......#.............#.......##
......#...........#...#..##....
.#..#..#....#..........#......#
...........#..#.....#....##....
###....#....##..#..##.....##...
#........#........#...#.##.##..
##.#.#........#..#.#..#.......#
.##.#.....#............#.......
.....#........#..##......##....
.#.####.#.##..................#
#...##.......#...#....#.#.##...
#.#.##...#.#......#.....#....#.
.........#....#...#....#.....#.
...#..#..#.#..#.##........##.#.
..#.##.#...#...#....#....##..#.
.#..#...####..........#.......#
....#...#...#...##.#.##......#.
.#....#...#.#..##..##.#.....#..
.....#....#......#.#####...###.
..#...##..#......#.#....#.....#
.##....##..###.#.....##.##.##..
#...#.#.........#....#....#....
...#.........#.##....##.#.#.#..
...#...#.#....#..#.#.......#.#.
#......#..#....##....#.........
...........#......#......###..#
#..#...#..##..#....#.....#.#.#.
#.#.....##..#..........###..#..
#...#.....#.......#..##...#....
...#....##.....#..##..#....#...
#...#.#......#..#...#........#.
.#....#...#...#.........##....#
..##...#.........#.......##..#.
......#.......#.....##....#..#.
.....##..#...#............#.#.#
...#....#.##..#...#.#....#.....
...#...........#.##....#..##.##
##......##....##...........#.#.
..##..##......#...#.##.##..#...
.#..##.#...##...#......###.##.#
###.#....##..#..#.##..##...##..
..#........##.#...#.......#....
.....##....##.#.###.....#....#.
#.##....#....##.....#..#.#.....
#.........#..##...##.......##..
.#....#......#.#...##..........
##..##.....##....###..#...#.#.#
..##.#.#..#......#.#....###..#.
.#.##.....##.......##.#.##..#..
..##...#........#.#.#.##.#..###
........#.......#...##....#.#..
...#..#...#.##..#...#.#.###.##.
..#.#....#..#...#..##.........#
#....#..##..##....#.........#..
.......#.......#....#....#.#...
...#.##...#...#..#....#.###.##.
##.##...#..........#....#......
#.##.#.....#..#............##.#
.##...#.#.#.##...........#..##.
.#...#....#.......##...##...#.#
.#......#..#...#...#....#.#....
...#..#..#...#..##..##.....#..#
.#.##..#.#...#..#.#...#...#...#
#.##..........#.##..#....#.....
##....#.#..........#..#....#...
..#..##.#.......#...#.##......#
....##......#......#.#.#.##....
###......#...##..#..........###
##.#.##.....###.#..#.#......#..
#.#.#........#..........#....#.
...#.#..#.......#......##.#....
......#.....#.#.#....###..#...#
.........#...#..#####..#.#..#..
..........#.#.#####.#..#.....#.
....#.......#.#....#.....##..#.
#...##.#..#.#........#.#..#..##
#......#..#.#.....##......#.##.
.##...#....#.##..#.....###..#..
#....#.#..##....##..#.#####....
.......##..........#......#....
......#.#...#............#.....
.......###.....##.#..#.#....#.#
...#...#..........#....##...##.
.#..#.#.#....#.#.....##..#.#..#
......#.#..#....#..#...#.......
##.#####............#.#.####.#.
#.....###.#.......##...###....#
......#.##..##.........#.#.....
.#.#......#..#.##......#......#
.#.#.#..#.#...##.....#..#.#..#.
.#.#....#......................
#.#..###...#...####.##.#....#.#
.....#............#....#..#.##.
#..#...#.#....#....#..#..#...#.
...#.......#..#.#....#.......#.
.#..#.#...#.#.####..#...#....##
....#..#..............####....#
.....#.#.###....#.#.#.#...#....
..####..#.#.##.##.##....#..#...
.#.#.#.###..#.##..............#
..#.#..#...#.....#.......#.##..
.#.#..#.....##...###.....#..#..
..#..#......#.##..#......##..#.
.....#.#.#..##..###.#..........
.##......#...#.##.......#..#..#
.......#...#.....###.##...##...
..##..#.#.......#..............
#.....#......#.#..#..#..#......
..###.......##...#.##....#.....
.....##...........##.....#...##
.#.#.####....###.#.......#...##
#.#..##.#.#.....#.#....#.......
.........#.#..#...............#
..##.#..#..#####.###.........#.
.#........#...#...#...#.##.#..#
.#.##..........#..##....#.#.#..
.##......#....#.#....##.#.#.#..
.......##.####..#..#.#..#.#...#
...#.....#..##..###.#..##...#..
#.......##..#####....#.......#.
#.#.##.................#...###.
................####...........
.#..#......#...###.............
......#.#.##.##.....#..........
.......#..#.#............##....
#........#..#....#......#.####.
...#.#....##..#..#.............
..#.#......#...#.#..#..........
###...###...........#......#...
#.###..###........###...#..###.
.#.....#...#.#...........##....
....#..##.....#..#......#......
#.###.#........#.#.##..........
#.#.#.#.#..#.#...#...##.#......
..###.......###..#.#.#.#.#.....
...#........#.......#.###..##..
.#........#...#.#........#..##.
#.......###..#....##.###...#..#
.##....###..##...........##...#
#...#..........#.....#..##..#..
#..##..#..##.#.........##......
..#.#..###..###.....#.......#..
#...#...........##.#.#.###.....
...#....#.....#.....#.##.#.##.#
...........##.......####...#..#
#.#...#..##..#.#..#..........#.
..#...#.##........#.#..........
.##.....#.#.#....#.#.......#.#.
.......#.##...#.##....#.#...#..
......#...##...###...#.....###.
##......#.##.####.##...##......
..#....#.#..###.#..##....#..#..
...##..###.....###.....#.......
...#.....#.#........#..#..##.#.
.....................#.....#.#.
.#...#...##.#..#..........#...#
#.....#..#....#..#.......####..
.##.......##......###.#..#...##
.#.##..#...#..........##.......
...##...........##..##......#..
#....##.##...#......##.#.##.##.
..##.##.#.#.#....#........#.#..
....#......#......##..##.#.#...
.............#.##...#..#...#...
.#..#...#.........#...........#
....#.....#..................#.
........##............#...#..##
.###.....##...#...#.##.....##..
...##.#.........##.#.#..#......
#...........##.#..#........#..#
....#....#..##.#..##..#..#..#.#
#..##..#............#...#.#.#..
#......#..##......#...##..#...#
....#.#..##.#.#...####...#.....
.##..#..##....#...#....#...##.#
##.....#.#........#....#.#.#...
......#.#...##....#.###.....#.#
..#..#............###.###.##.#.
#..#.##.##.##..#...#.#.##..#...
....#..#.#...#......#..###.....
.#........#...###.....#...#....
....##.##....#..#...#.#####.#.#
...#..#...#.#.....#....#...###.
..........####...##............
.....#....##...##......#..#...#
..#...#.####......#...#..#..###
.#.....#....#..#...###..#.#....
..#..#......#.#...#.....##....#
.....##....#....#...#.....##...
#............##.#....#.#.#..#..
#......#......#....#.#..##.#...
#.#......##.....#.#..##.#.#....
.#.###..#.#......##...........#
#.#.........##..#.#.##......#..
##....####...##...........#....
....###.#..##.#.#.##...##.....#
..###.......##.......#......#..
..#.###.##.#...................
...#.#...#..#..#..##.###...#.#.
#...#..#...#..#....#..#...#....
....#........#.#.#.##.##.#..#.#
...#....#.#...#..#....#.#.#....
..#...#..##.#....##...###...##.
#......#.....#.....#....####.#.
...##.#..#.#.....#..#..##.#....
.####.#..#...#.#......#......#.
..#.#....#..#..##.#......##....
....#...#.#..#...#...##........
##..#.#....#..#.........#..##..
...#.......#....#..##...###..##
#......##.#..#..#..#..###.#.###
.#..##.#...##...#.............#
###.........#...###.#.#..#....#
.#.....#..#........#.#.......#.
#..#.#.....#.........###..#....
#..##.....#.#....#.###.....#..#
....#..#.......##..#.#..##....#
##.##..#....#..#.#.###.........
..##....#........#..#..#.##.#.#
.#....#...##..#.#.....#..##..#.
#..#.......#......#...#...#.##.
...##.#......#.#..#......#.....
......#...#.##.#....#...#.##.#.
#.....#..#.#.#...##...#........
....#.#..#.#.....#....#.#..#...
....#.#...###............#.....
.#.#...##.......#....#.##...#.#
.....#.##......#.#..#...#....#.
.###....#...#........#.........
..#.....#..#.#.#..##...#..#....
...###..#....#.....#.........##
#....#....###...#.#............
.#..##.....#...........#.#..#..
..#.#.#.......##..#.#..........
.#...#...####.#...#####.....#.#
..#....##.....#..#...#.........
#.#......#.##.........#......##
..#.#...#.##..#....#....#.##...
#....#......##.#..#......#.#.#.
#.#.............##..#.#........
..#.###.......##.....##.#..##.#
.........#........#...#..#....#
.........##.#.#..#..#....#....#
##..#..#.#.....##.........#.#.#
..##.##..#.##..........##.#..#.
...#..#####.......#.........#..)";

using Map = std::vector<std::string>;

unsigned int tree_count(unsigned int right_step,unsigned int down_step, Map const& map) {
    std::cout << "\n\nTree Count for slope right:" << right_step << " down:" << down_step;
    unsigned int row {0};
    unsigned int column {0};
    unsigned int result = std::accumulate(map.begin(), map.end(), 0,[&row, &column,right_step,down_step](unsigned int sum,std::string const& entry){
        unsigned int index {0};
        // Log
        std::cout << "\n";
        if (row % down_step == 0) {
            for (char c : entry) {
                if (index++ == column) std::cout << '[' << c << ']';
                else std::cout << c;
            }
            if (entry[column] == '#') {
                ++sum;
            }
            std::cout << " count = " << sum;
            column = (column + right_step) % entry.size(); // map pattern repeat
        }
        else {
            // step over this row
            for (char c : entry) {
                if (index++ == column) std::cout << '(' << c << ')';
                else std::cout << c;
            }
        }
        ++row;
        return sum;
    });
    return result;
}

int main(int argc, const char * argv[]) {
    std::basic_istringstream<char> in {pData};
    std::string sMapRow;
    std::vector<std::string> map;
    while (in >> sMapRow) {
        map.push_back(sMapRow);
    }
    std::vector<int> counts;
    counts.push_back(tree_count(1,1,map));
    counts.push_back(tree_count(3,1,map)); // Part 1 answer
    counts.push_back(tree_count(5,1,map));
    counts.push_back(tree_count(7,1,map));
    counts.push_back(tree_count(1,2,map));
    std::cout << "\n";
    // Trap! Provide uint64_t typed init value 1 to have accumulate be instantiated to operate on uint64_t result :)
    auto counts_product = std::accumulate(counts.begin(), counts.end(), uint64_t(1),[](auto const product,auto const count) {
        auto result {product * count};
        std::cout << "\n" << product << " * " << count << " = " << result;
        return result;
    });
    std::cout << "\n\nProduct = " << counts_product;
    std::cout << "\n";
    std::cout << "\n";
    return 0;
}
