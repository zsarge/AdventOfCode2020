fs = require("fs");
var input = fs.readFileSync("input.txt", "utf8"); // REAL INPUT
// var input = fs.readFileSync("test_input.txt", "utf8");

input = input.split("\n");

var seats = [];
var columns = [];

function generateSeats() {
	seats = [];
	for (let i = 0; i < 127; i++) {
		seats.push(i);
	}
}

function generateColumns() {
	columns = [];
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
	});
	return [seats[0], columns[0]];
}

function getSeatID(array) {
	return array[0] * 8 + array[1];
}

// _________________________________

var allSeatIDs = [];

input.forEach((pattern) => {
	let rowAndColumn = getRowAndColumn(pattern);
	let seatID = getSeatID(rowAndColumn);
	allSeatIDs.push(seatID);
});

allSeatIDs.map((x) => parseInt(x));
allSeatIDs.sort(function (a, b) {
	return a - b;
});

function getYourID() {
	let lastValue = 0;
	var yourID = 0;
	Object.values(allSeatIDs).forEach((key) => {
		key = parseInt(key);
		if (key - lastValue > 1) yourID = key;
		lastValue = key;
	});
	return yourID - 1;
}

console.log(getYourID());
