fs = require("fs");
// var input = fs.readFileSync("input.txt", "utf8"); // REAL INPUT
var input = fs.readFileSync("test_input.txt", "utf8");

input = input.split("\n");

var seats = [];
var columns = [];

function generateSeats() {
	for (let i = 0; i < 127; i++) {
		seats.push(i);
	}
}

function generateColumns() {
	for (let i = 0; i < 8; i++) {
		columns.push(i);
	}
}

function takeLower(array) {
	let length = array.length;
	array.splice(Math.round(length / 2));
}

function takeUpper(array) {
	let length = array.length;
	array.splice(0, Math.round(length / 2));
}

function getRowAndColumn(string) {
	generateColumns();
	generateSeats();
	Object.values(string).forEach((char) => {
		if (char == "F") {
			takeLower(seats);
		} else if (char == "B") {
			takeUpper(seats);
		} else if (char == "L") {
			takeLower(columns)
		} else if (char == "R") {
			takeUpper(columns)
		}
	});
	return [seats[0], columns[0]]
}

function seatID(array) {
	return ((array[0] * 8) + array[1])
}

let result = getRowAndColumn("FFFBBBFRRR")
console.log(result);
console.log(seatID(result));
