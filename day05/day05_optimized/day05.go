/* Advent of Code: day 5, parts 1 and 2
 * https://adventofcode.com/2020/day/5
 * using go
 * by Zack Sargent
 *
 * I originally tried to do this when the challenge opened at midnight.
 * Apparently, I don't write good code when sleep deprived, so this is
 * an improved version.
 */

package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"math"
	"sort"
	"strings"
)

/*
 * For takeUppper and takeLower, know that low and
 * high are the bounds of the range to use.
 *
 * Starting from 0 to 127, applying takeLower would
 * keep the range 0 through 63. Subsequently applying
 * takeUpper would keep 32 through 63.
 *
 * These functions are applied by the seat pattern until
 * the bounds converge on a single number. This number
 * is stored as the low bound in the code.
 */

func takeUpper(low int, high int) int {
	if high-low == 1 {
		low = high
		return low
	}
	low += int(math.Ceil(float64(high-low) / 2))
	return low
}

func takeLower(low int, high int) int {
	high -= int(math.Ceil(float64(high-low) / 2))
	return high
}

func getSeatPosition(seat string) (int, int) {
	rowLow, rowHigh := 0, 127
	colLow, colHigh := 0, 7

	for _, r := range seat {
		char := string(r)
		if char == "F" {
			rowHigh = takeLower(rowLow, rowHigh)
		} else if char == "B" {
			rowLow = takeUpper(rowLow, rowHigh)
		} else if char == "L" {
			colHigh = takeLower(colLow, colHigh)
		} else if char == "R" {
			colLow = takeUpper(colLow, colHigh)
		}
	}

	return rowLow, colLow
}

func getId(seat string) int {
	row, col := getSeatPosition(seat)
	seatId := (row * 8) + col
	return seatId
}

func max(numbers []int) int {
	max := numbers[0]
	for _, num := range numbers {
		if num > max {
			max = num
		}
	}
	return max
}

// Part 1: Find the highest seat ID on a boarding pass.
func part1(input []uint8) []int {
	var seatIds []int

	// get the id for every pattern given
	for _, seat := range strings.Split(strings.TrimSuffix(string(input), "\n"), "\n") {
		seatIds = append(seatIds, getId(string(seat)))
	}

	// get the max of those seat ids
	fmt.Println("Part 1: ")
	fmt.Println(max(seatIds))

	return seatIds
}

// Part 2: Find the ID of your seat.
// (your seat being a seat that has an ID directly
// above and below it, but is not included in the
// list of other people's seats)
func part2(seatIds []int) int {
	sort.Ints(seatIds)
	lastValue := seatIds[0]

	for _, seat := range seatIds {
		// find the seat that is skipped
		if seat-lastValue > 1 {
			return (seat - 1)
		}
		lastValue = seat
	}

	return -1
}

func main() {
	input, err := ioutil.ReadFile("input.txt")

	if err != nil {
		log.Fatal(err)
	}

	seatIds := part1(input)

	fmt.Println("Part 2: ")
	fmt.Println(part2(seatIds))
}
