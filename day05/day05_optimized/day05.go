package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"math"
	"strings"
)

func takeUpper(low int, high int) (int, int) {
	if high-low == 1 {
		low = high
		return low, high
	}
	low += int(math.Ceil(float64(high-low) / 2))
	return low, high
}

func takeLower(low int, high int) (int, int) {
	high -= int(math.Ceil(float64(high-low) / 2))
	return low, high
}

func getSeatPosition(seat string) (int, int) {
	rowLow, rowHigh := 0, 127
	colLow, colHigh := 0, 7

	for _, r := range seat {
		c := string(r)
		if c == "F" {
			rowLow, rowHigh = takeLower(rowLow, rowHigh)
		} else if c == "B" {
			rowLow, rowHigh = takeUpper(rowLow, rowHigh)
		} else if c == "R" {
			colLow, colHigh = takeUpper(colLow, colHigh)
		} else if c == "L" {
			colLow, colHigh = takeLower(colLow, colHigh)
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

func part1(input []uint8) {
	var seatIds []int

	// get the id for every pattern given
	for _, seat := range strings.Split(strings.TrimSuffix(string(input), "\n"), "\n") {
		seatIds = append(seatIds, getId(string(seat)))
	}

	// get the max of those seat ids
	fmt.Println("Part 1: ")
	fmt.Println(max(seatIds))
}

func main() {
	input, err := ioutil.ReadFile("input.txt")

	if err != nil {
		log.Fatal(err)
	}

	part1(input)
}
