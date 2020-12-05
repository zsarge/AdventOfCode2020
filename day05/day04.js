fs = require("fs");
var input = fs.readFileSync("input.txt", "utf8"); // REAL INPUT
// var input = fs.readFileSync("test_input.txt", "utf8");

input = input.split("\n");

var seats = [];
var columns = [];

function generateSeats() {
	seats = []
	for (let i = 0; i < 127; i++) {
		seats.push(i);
	}
}

function generateColumns() {
	columns = []
	for (let i = 0; i < 8; i++) {
		columns.push(i);
	}
}

function takeLower(array) {
	let length = array.length;
	array.splice(Math.ceil(length / 2));
}

function takeUpper(array) {
	let length = array.length;
	array.splice(0, Math.ceil(length / 2));
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
			takeLower(columns);
		} else if (char == "R") {
			takeUpper(columns);
		}
		console.log(`seats ${seats}\ncolumns ${columns}`);
	});
	if (columns.length > 1) takeUpper(columns);
	if (columns.length > 1) throw "error";
	if (seats.length > 1) throw "error";
	// console.log("\nSEAT ID = " + getSeatID([seats[0], columns[0]]));
	// console.log("\n\nEND\n\n");
	return [seats[0], columns[0]];
}

function getSeatID(array) {
	return array[0] * 8 + array[1];
}

var maxSeatID = [];
input.forEach((pattern) => {
	maxSeatID.push(getSeatID(getRowAndColumn(pattern)));
});
// console.log(JSON.stringify(maxSeatID));
console.log(Math.max(...maxSeatID));

// NOT 988
