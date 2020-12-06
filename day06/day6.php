<?php
/* 
 * advent of code, day 6, part 1
 * https://adventofcode.com/2020/day/6
 * using PHP 7.2.24
 * by Zack Sargent
 *
 * Note: this is my first time using PHP.
 */

function replace($s) 
{
	return str_replace("\n","", $s);
}

function getInput() 
{
	$filename = "input.txt";
	// $filename = "test_input.txt";

	$resource = fopen($filename, "r");
	$input_file = fread($resource, filesize($filename));

	$input_file = rtrim($input_file, "\n");
	$raw_array = explode("\n\n", $input_file);

	$formatted_array = array_map('replace', $raw_array);

	fclose($resource);
	return $formatted_array;
}

function getNumberOfQuestions($str) 
{
	$letters = str_split($str);
	$answered = array();

	foreach ($letters as $char) {
		$answered[$char] = true;
	}
	return count($answered);
}

$input = getInput();
$total = 0;

foreach ($input as $value) {
	$total += getNumberOfQuestions($value);
}

echo "Total questions:\n";
echo $total , "\n";

// too high : 6533
?>
