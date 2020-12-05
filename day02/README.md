# [Day 2: Password Philosophy](https://adventofcode.com/2020/day/2)

> [Go back to main repo](https://github.com/zsarge/AdventOfCode2020)

This day was written in C.

This should work with GNU Make 4.1

gcc should also work instead of make.

## Installation:

(I have not tested everything listed here.)

Linux users should probably already have make, but if you don't:

| Package manager | Command                                                      |
| :-------------: | ------------------------------------------------------------ |
|       dnf       | `sudo dnf install make`                                      |
|       apt       | `sudo apt-get install build-essential`                       |
|       yum       | `yum groupinstall "Development Tools"` or `yum install make` |

Windows users:

Windows doesn't have make by default, but there are [still many ways](https://stackoverflow.com/questions/32127524/how-to-install-and-use-make-in-windows) [to compile C programs.](https://nullprogram.com/blog/2016/06/13/)

**To run day 2, part 1:**

```
$ make day2 && ./day2
```

**To run day 2, part 2:**

```
$ make day2_part2 && ./day2_part2
```

# Prompt:

Your flight departs in a few days from the coastal airport; the easiest way down to the coast from here is via toboggan.

The shopkeeper at the North Pole Toboggan Rental Shop is having a bad day. "Something's wrong with our computers; we can't log in!" You ask if you can take a look.

Their password database seems to be a little corrupted: some of the passwords wouldn't have been allowed by the Official Toboggan Corporate Policy that was in effect when they were chosen.

To try to debug the problem, they have created a list (your puzzle input) of passwords (according to the corrupted database) and the corporate policy when that password was set.

For example, suppose you have the following list:

```
1-3 a: abcde
1-3 b: cdefg
2-9 c: ccccccccc
```

Each line gives the password policy and then the password. The password policy indicates the lowest and highest number of times a given letter must appear for the password to be valid. For example, 1-3 a means that the password must contain a at least 1 time and at most 3 times.

In the above example, 2 passwords are valid. The middle password, cdefg, is not; it contains no instances of b, but needs at least 1. The first and third passwords are valid: they contain one a or nine c, both within the limits of their respective policies.

**How many passwords are valid** according to their policies?

> Your puzzle answer was `398`.

## Part Two

While it appears you validated the passwords correctly, they don't seem to be what the Official Toboggan Corporate Authentication System is expecting.

The shopkeeper suddenly realizes that he just accidentally explained the password policy rules from his old job at the sled rental place down the street! The Official Toboggan Corporate Policy actually works a little differently.

Each policy actually describes two **positions in the password**, where 1 means the first character, 2 means the second character, and so on. (Be careful; Toboggan Corporate Policies have no concept of "index zero"!) **Exactly one of these positions** must contain the given letter. Other occurrences of the letter are irrelevant for the purposes of policy enforcement.

Given the same example list from above:

```
1-3 a: abcde is valid: position 1 contains a and position 3 does not.
1-3 b: cdefg is invalid: neither position 1 nor position 3 contains b.
2-9 c: ccccccccc is invalid: both position 2 and position 9 contain c.
```

How many passwords are valid according to the new interpretation of the policies?

> Your puzzle answer was `562`.
