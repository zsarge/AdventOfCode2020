// advent of code, day 1, part 2
// https://adventofcode.com/2020/day/1
// using node.js
// by Zack Sargent

const expenses = require("./input.js")["expenses"];

// O(n^3)
// not production code, but it still only takes 1 second
function findDifference(array) {
	for (let i = 0; i < array.length; i++) {
		for (let j = 0; j < array.length; j++) {
			for (let k = 0; k < array.length; k++) {
				if (array[i] + array[j] + array[k] === 2020) {
					return [array[i], array[j], array[k]];
				}
			}
		}
	}
	throw "Did not find solution";
}

function calculateExpenses(array) {
	let numbers = findDifference(array);
	return numbers[0] * numbers[1] * numbers[2];
}

console.log(calculateExpenses(expenses));
