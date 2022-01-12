# advent_of_code_2020
My solutions to the Advent of Code 2020 puzzles

# day 23
Lessons learned from day 23
* I solved part 1 operating directly on the string.
    * In C++ the string type has all the operations required to cut, paste and rotate to emulate the moves.
    * And cups having only one digit numbers allowed moving them around as a single digit in the string.

* For part 2 I first though I was clever to NOT initialize all cups in memory.
    * My idea was to instantiate cups as they came into play.
    * I invented the following game state to keep track of the range of unplayed cups

```
        // [ cups       ]      ... not in cups            [ cups ]
        //            expand --> 
        // current c c c [unplayed.first..unplayed.second] c c c  |
        //    |                                            |     end
        //  begin                                     expansion_point         

        // [ cups       ]      ... not in cups            [ cups ]
        //                                          <-- expand
        // current c c c [unplayed.first..unplayed.second] c c c  |
        //    |                                            |     end
        //  begin                                     expansion_point         

```
* I came quite far into implementing this mechanism.
    * When I select next I expanded downwards into the unplayed range if the selected one had not yet been played.
    * When I picked up cups I expanded upwards into the unplayed range
    * And when I rotated to make next cup the current I expanded into unplayed range if required.

* From this I learned that the next cup will always move into the unplayed range.
    * In hind sight this may be obvious?
    * But I had done some initial tests and discovered the range of cups in play seemed to NOT grow with the moves?
    * The reason for this was that I had gotten the "expand unplayed cups range" mechanism wrong.
    * And I was so occupied trying out my clever "save game state real estate" that I did not think this through properly.

* In the following log example the range of unplayed cups are between cup 30 and cup 1000000.

```
...

Cups  30 1000000 8 9 11 12 13 15 16 17 19 20 21 23 24 25 27 28 29 1 3 4 6 7 2 5 10 14 18 22 26

Picked  31 32 33
Remaining  30 1000000 8 9 11 12 13 15 16 17 19 20 21 23 24 25 27 28 29 1 3 4 6 7 2 5 10 14 18 22 26

Selected : 29

picked reinserted  30 1000000 8 9 11 12 13 15 16 17 19 20 21 23 24 25 27 28 29 31 32 33 1 3 4 6 7 2 5 10 14 18 22 26

Cups  34 1000000 8 9 11 12 13 15 16 17 19 20 21 23 24 25 27 28 29 31 32 33 1 3 4 6 7 2 5 10 14 18 22 26 30

Picked  35 36 37
Remaining  34 1000000 8 9 11 12 13 15 16 17 19 20 21 23 24 25 27 28 29 31 32 33 1 3 4 6 7 2 5 10 14 18 22 26 30

Selected : 33

picked reinserted  34 1000000 8 9 11 12 13 15 16 17 19 20 21 23 24 25 27 28 29 31 32 33 35 36 37 1 3 4 6 7 2 5 10 14 18 22 26 30

Cups  38 1000000 8 9 11 12 13 15 16 17 19 20 21 23 24 25 27 28 29 31 32 33 35 36 37 1 3 4 6 7 2 5 10 14 18 22 26 30 34

Picked  39 40 41
Remaining  38 1000000 8 9 11 12 13 15 16 17 19 20 21 23 24 25 27 28 29 31 32 33 35 36 37 1 3 4 6 7 2 5 10 14 18 22 26 30 34

Selected : 37

picked reinserted  38 1000000 8 9 11 12 13 15 16 17 19 20 21 23 24 25 27 28 29 31 32 33 35 36 37 39 40 41 1 3 4 6 7 2 5 10 14 18 22 26 30 34

...

```
* It is clear the range of unplayed cups remains at the beginning of the list (and thus the next current will always step up into the range of unplayed cups).
    * We can also suspect the 1000000 and below will NOT come into play until we have moved one full turn of all the cups?

* By initiating more cups at the beginning I could verify that my "expansion" mechanism gives me the same result as if I emulate the game with pre-instantiated cups?

```
Selected : 29

picked reinserted  30 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 999998 999999 1000000 8 9 11 12 13 15 16 17 19 20 21 23 24 25 27 28 29 31 32 33 1 3 4 6 7 2 5 10 14 18 22 26

Cups  34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 999998 999999 1000000 8 9 11 12 13 15 16 17 19 20 21 23 24 25 27 28 29 31 32 33 1 3 4 6 7 2 5 10 14 18 22 26 30

Picked  35 36 37
Remaining  34 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 999998 999999 1000000 8 9 11 12 13 15 16 17 19 20 21 23 24 25 27 28 29 31 32 33 1 3 4 6 7 2 5 10 14 18 22 26 30

Selected : 33

picked reinserted  34 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 999998 999999 1000000 8 9 11 12 13 15 16 17 19 20 21 23 24 25 27 28 29 31 32 33 35 36 37 1 3 4 6 7 2 5 10 14 18 22 26 30

Cups  38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 999998 999999 1000000 8 9 11 12 13 15 16 17 19 20 21 23 24 25 27 28 29 31 32 33 35 36 37 1 3 4 6 7 2 5 10 14 18 22 26 30 34

Picked  39 40 41
Remaining  38 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 999998 999999 1000000 8 9 11 12 13 15 16 17 19 20 21 23 24 25 27 28 29 31 32 33 35 36 37 1 3 4 6 7 2 5 10 14 18 22 26 30 34

Selected : 37

picked reinserted  38 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 999998 999999 1000000 8 9 11 12 13 15 16 17 19 20 21 23 24 25 27 28 29 31 32 33 35 36 37 39 40 41 1 3 4 6 7 2 5 10 14 18 22 26 30 34

Cups  42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 999998 999999 1000000 8 9 11 12 13 15 16 17 19 20 21 23 24 25 27 28 29 31 32 33 35 36 37 39 40 41 1 3 4 6 7 2 5 10 14 18 22 26 30 34 38

Picked  43 44 45
Remaining  42 46 47 48 49 50 51 52 53 54 55 56 57 58 59 999998 999999 1000000 8 9 11 12 13 15 16 17 19 20 21 23 24 25 27 28 29 31 32 33 35 36 37 39 40 41 1 3 4 6 7 2 5 10 14 18 22 26 30 34 38

Selected : 41

picked reinserted  42 46 47 48 49 50 51 52 53 54 55 56 57 58 59 999998 999999 1000000 8 9 11 12 13 15 16 17 19 20 21 23 24 25 27 28 29 31 32 33 35 36 37 39 40 41 43 44 45 1 3 4 6 7 2 5 10 14 18 22 26 30 34 38

Cups  46 47 48 49 50 51 52 53 54 55 56 57 58 59 999998 999999 1000000 8 9 11 12 13 15 16 17 19 20 21 23 24 25 27 28 29 31 32 33 35 36 37 39 40 41 43 44 45 1 3 4 6 7 2 5 10 14 18 22 26 30 34 38 42
```
* Especially the final states are the same (after adjusting for the invisible unplayed cups in the first log)

```
// Cups  46                                                      1000000 8 9 11 12 13 15 16 17 19 20 21 23 24 25 27 28 29 31 32 33 35 36 37 39 40 41 43 44 45 1 3 4 6 7 2 5 10 14 18 22...
// Cups  46 47 48 49 50 51 52 53 54 55 56 57 58 59 999998 999999 1000000 8 9 11 12 13 15 16 17 19 20 21 23 24 25 27 28 29 31 32 33 35 36 37 39 40 41 43 44 45 1 3 4 6 7 2 5 10 14 18 22...
```


* It seems there may be a pattern in how the played cups are arranged?
    * As soon as we move start picking from the unplayed range of cups we will always pick a sequence of cups that are in number order.
    * These picked cups will then be inserted in the same order after the cup with an index two (2) below the first picked cup.
    * We get these groupings clockwise of current:  ... 11 12 13    15 16 17    19 20 21    23 24 25 ...
    * With the intermediate (missing) cups "left behind" as 10 14 18 22 26 30 34...

* Note to self: I seem to be keen on "trying something new" before "trying the old"?

* I then fell into the trap of std::ranges::iota_view taking a range [begin,end[ and NOT {first,count}.
    * For some time I also fell into the trap of thinking of 1..9 as being 10 elements *sigh*
    * I also almost fell into the trap of NOT setting the Id of the last cup to 1 million (again the cup numbers start at 1, not 0).
* Here is the correct generation of 
    * Note: It is not clear if using ranges for this is more readable (especially as the view range requires a static_cast to get both boundaries to be of the same type)
```
    // fill up the range 10...1000000 (part 2, no effect for part 1 cups count)
    std::ranges::copy(std::ranges::iota_view{cups.size()+1,static_cast<size_t>(MAX+1)},std::back_inserter(cups));
```