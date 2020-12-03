// advent of code, day 1
// https://adventofcode.com/2020/day/1
// using node.js
// by Zack Sargent

const expenses = require("./input.js")["expenses"];
const testExpenses = [1721, 979, 366, 299, 675, 1456];

// O(n^2)
// However, it only took about 1 second,
// so I think it's good enough
function findDifference(array) {
	for (let i = 0; i < array.length; i++) {
		for (let j = 0; j < array.length; j++) {
			if (array[i] + array[j] === 2020) {
				return [array[i], array[j]];
			}
		}
	}
	throw "Did not find solution";
}

function calculateExpenses(array) {
	let numbers = findDifference(array);
	return numbers[0] * numbers[1];
}

console.log(calculateExpenses(expenses));
// answer: 290784