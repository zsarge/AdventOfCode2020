<?php
/* 
 * advent of code, day 6, part 1
 * https://adventofcode.com/2020/day/6
 * using PHP 7.2.24
 * by Zack Sargent
 */

function replace($s) {
	return str_replace("\n","", $s);
}

function getInput() {
	// $filename = "input.txt";
	$filename = "test_input.txt";

	$resource = fopen($filename, "r");
	$input_file = fread($resource, filesize($filename));

	$raw_array = explode("\n\n", $input_file);

	$formatted_array = array_map('replace', $raw_array);

	fclose($resource);
	return $formatted_array;
}

$input = getInput();
$answered = array();

function returnTrue() {
	return true;
}

$alpha = range('a', 'z');
$alpha = array_fill_keys($alpha, true);

foreach ($input as $form) {
	foreach ($alpha as $char => $value) {
		// If a char is not found in the form,
		if (strpos($form, $char) === false) {
			// mark it false
			$alpha[$char] = false;
		}
	}
}

echo "Number of questions everone answered:\n";
echo count(array_filter($alpha)), "\n";


?>
