
to run solution 1:

```
$ mcs -out:test.exe day7.cs && mono test.exe

```
light red bags contain 1 bright white bag, 2 muted yellow bags.
dark orange bags contain 3 bright white bags, 4 muted yellow bags.
bright white bags contain 1 shiny gold bag.
muted yellow bags contain 2 shiny gold bags, 9 faded blue bags.
shiny gold bags contain 1 dark olive bag, 2 vibrant plum bags.
dark olive bags contain 3 faded blue bags, 4 dotted black bags.
vibrant plum bags contain 5 faded blue bags, 6 dotted black bags.
faded blue bags contain no other bags.
dotted black bags contain no other bags.

contain [1-9] shiny gold bag -> muted yellow bags, bright white bags
    contain [1-9] muted yellow bag -> no results
    contain [1-9] bright white bag -> dark orange bags, light red bags
        contain [1-9] dark orange bags -> no results
        contain [1-9] light red bags -> no results


265 is correct
