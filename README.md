# [Advent Of Code (2020)](https://adventofcode.com/2020/)

[![MIT License](https://img.shields.io/github/license/zsarge/AdventOfCode2020?style=flat-square)](https://github.com/zsarge/AdventOfCode2020/blob/main/LICENSE)
[![Last Commit](https://img.shields.io/github/last-commit/zsarge/AdventOfCode2020?style=flat-square)](https://github.com/zsarge/AdventOfCode2020/graphs/commit-activity)
[![Languages Used](https://img.shields.io/github/languages/count/zsarge/AdventOfCode2020?style=flat-square)](https://github.com/zsarge/AdventOfCode2020/commits/main)
[![Language Percentage](https://img.shields.io/github/languages/top/zsarge/AdventOfCode2020?style=flat-square)](https://github.com/zsarge/AdventOfCode2020/commits/main)

> Advent of Code is an Advent calendar of small programming puzzles
> for a variety of skill sets and skill levels that can be solved in
> any programming language you like. [[source]](https://adventofcode.com/2020/about)

I am a high schooler doing Advent of Code as a fun exercise in programming, not a professional programmer attempting to get a high score.

I am trying to do each day in a different programming language, and make each solution as idiomatic as I can for each language.

## Solution Overview

Click the language name for details on how to run the solutions. Click "Pt 1" for part 1 or "Pt 2" for part 2.

|                         Day                          |                                     Solutions                                      | Language                                     | Comments                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| :--------------------------------------------------: | :--------------------------------------------------------------------------------: | :------------------------------------------- | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
|       [1](https://adventofcode.com/2020/day/1)       |                 [Pt 1](day01/day1.js), [Pt 2](day01/day1_part2.js)                 | [Javascript](day01/README.md)                | This is a very inefficient solution, but it still only takes ~0.519s. I heard of Advent of Code the day I started this challenge, so I handled input by directly formatting it as an array. I still need to go back and make it parse the input directly.                                                                                                                                                                                                           |
|       [2](https://adventofcode.com/2020/day/2)       |                  [Pt 1](day02/day2.c), [Pt 2](day02/day2_part2.c)                  | [C](daPy02/README.md)                         | On my system, this solution takes 0.011s. It's amazing how much my standards drop when I start using Javascript.                                                                                                                                                                                                                                                                                                                                                    |
|       [3](https://adventofcode.com/2020/day/3)       |                             [Pts 1 & 2](day03/day3.rb)                             | [Ruby](day03/README.md)                      | This was me experimenting with OOP, but I don't think I executed it that well. I have not used Ruby in a while. My solution could use several improvements.                                                                                                                                                                                                                                                                                                         |
|       [4](https://adventofcode.com/2020/day/4)       |                [Pt 1](day04/day04.py), [Pt 2](day04/day04_part2.py)                | [Python](day04/README.md)                    | This took me two hours because I had a typo in two characters.                                                                                                                                                                                                                                                                                                                                                                                                      |
| [5 (original)](https://adventofcode.com/2020/day/5)  | [Pt 1](day05/day05_original/day05.js), [Pt 2](day05/day05_original/day05_part2.js) | [Javascript](day05/day05_original/README.md) | I tried to do this one from challenge open. I placed 8460 in part 1 and 8816 in part 2. I recorded me solving it, and looking back, I spent most of the time not understanding the directions. I think I will continue solving the problems when I am wide awake, rather than trying to make a rush at midnight.                                                                                                                                                    |
| [5 (optimized)](https://adventofcode.com/2020/day/5) |                    [Pts 1 & 2](day05/day05_optimized/day05.go)                     | [Go](day05/day05_optimized/README.md)        | After realizing how bad my original solution was, I improved it in Go. Coming from Javascript, I was originally annoyed by Go not letting me leave variables unused, but I realize now that it actually prevented some errors I likely would have made in a less strict language. I also thought Go's implementation of strings would be more annoying, but I figured it out and it wasn't that bad. Go is also impressively fast. Overall, I am impressed with Go. |
|       [6](https://adventofcode.com/2020/day/6)       |                [Pt 1](day06/day6.php), [Pt 2](day06/day6_part2.php)                | [PHP](day06/README.md)                       | This is my first time using PHP. I thought I would hate it more, but it's alright for short programs. Using `$` for variables isn't great, but isn't that bad. Being on a unix system might have improved my experience.                                                                                                                                                                                                                                            |

---

Out of all my solutions, I am most happy with Day 2, and Day 5 (optimized).

---

My friend Kevin is also doing Advent of Code, all in Javascript.
You can check out his solutions **[here](https://github.com/kevinuulong/aoc-2020)**
